#pragma once
#include <string>
#include <utility>
#include <vector>

class Day12
{
public:
    Day12(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::vector<std::pair<int, int>> get_neighbors(const std::pair<int, int> node) const;
    bool in_boundaries(std::pair<int, int> node) const;

    std::string mInputFile;
    std::vector<std::string> mMap;

    std::pair<int, int> mStart;
    std::pair<int, int> mEnd;
    std::vector<std::vector<int>> mVisited;
};
