#pragma once
#include <string>
#include <utility>
#include <vector>
#include "../utils/point2d.h"

class Day09
{
public:
    Day09(std::string path);
    int Puzzle1();
    long long Puzzle2();

private:
    void ReadData();

    void move_head(utils::Point2D &head, const std::string &movement);
    void move_next_to(const utils::Point2D &p1, utils::Point2D &p2);

    int move_rope(std::vector<utils::Point2D> &rope);

    std::string mInputFile;
    std::vector<std::pair<std::string, int>> mMovs;
};
