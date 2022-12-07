#pragma once
#include <memory>
#include <unordered_map>
#include <string>

struct Entry : public std::enable_shared_from_this<Entry>
{
    Entry(const std::string &name, bool isFolder, int size = 0);

    void add_subfolder(const std::string &name);
    void add_file(const std::string &name, int size);

    std::string mName;
    int mSize;
    bool mIsFolder;
    std::unordered_map<std::string, std::shared_ptr<Entry>> mChilds;
    std::shared_ptr<Entry> mParent;
};

struct CmpEntry
{
    bool operator()(const std::shared_ptr<Entry> &left, const std::shared_ptr<Entry> &right) const
    {
        return left->mSize < right->mSize;
    }
};

class Day07
{
public:
    Day07(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::shared_ptr<Entry> mRootFolder;
};
