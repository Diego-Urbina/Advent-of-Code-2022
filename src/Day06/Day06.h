#pragma once
#include <string>

class Day06
{
public:
    Day06(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();
    int find_marker(int marker_size);

    std::string mInputFile;
    std::string mData;
};
