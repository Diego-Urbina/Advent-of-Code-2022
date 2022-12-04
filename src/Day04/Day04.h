#pragma once
#include <string>
#include <utility>
#include <vector>
#include "../utils/interval.h"

class Day04
{
public:
    Day04(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<std::pair<utils::Interval, utils::Interval>> mSectionPairs;
};
