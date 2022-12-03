#pragma once
#include <utility>
#include <string>
#include <vector>

class Day02
{
public:
    Day02(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<std::pair<char, char>> mStrategy;
};
