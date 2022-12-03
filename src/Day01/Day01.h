#pragma once
#include <memory>
#include <string>
#include <queue>

struct Elf
{
    int mCalories;

    bool operator<(const Elf &other) { return this->mCalories < other.mCalories; }
};

struct Cmp
{
    bool operator()(const std::unique_ptr<Elf> &left, const std::unique_ptr<Elf> &right) const
    {
        return left->mCalories < right->mCalories;
    }
};

class Day01
{
public:
    Day01(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::priority_queue<std::unique_ptr<Elf>, std::vector<std::unique_ptr<Elf>>, Cmp> mElfs;
};
