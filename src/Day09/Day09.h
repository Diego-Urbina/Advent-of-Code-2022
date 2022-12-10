#pragma once
#include <string>
#include <utility>
#include <vector>

struct Point
{
    int x{0};
    int y{0};

    bool operator<(const Point &b) const { return x < b.x || (x == b.x && y < b.y); }
};

class Day09
{
public:
    Day09(std::string path);
    int Puzzle1();
    long long Puzzle2();

private:
    void ReadData();

    void move_head(Point &head, const std::string &movement);
    void move_next_to(const Point &p1, Point &p2);

    int move_rope(std::vector<Point> &rope);

    std::string mInputFile;
    std::vector<std::pair<std::string, int>> mMovs;
};
