#pragma once
#include <string>
#include <vector>

class Day08
{
public:
    Day08(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();
    bool is_visible(int row, int col);
    int scenic_score(int row, int col);

    std::string mInputFile;
    std::vector<std::vector<int>> mTrees;
};
