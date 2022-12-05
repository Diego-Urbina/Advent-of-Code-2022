#pragma once
#include <stack>
#include <string>
#include <vector>

struct Move
{
    int quantity;
    int from;
    int to;
};

class Day05
{
public:
    Day05(std::string path);
    std::string Puzzle1();
    std::string Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<std::stack<char>> mCrateStacks;
    std::vector<Move> mMoves;
};
