#pragma once
#include <functional>

namespace utils
{
struct Point2D
{
    int x{0};
    int y{0};

    bool operator<(const Point2D &b) const { return x < b.x || (x == b.x && y < b.y); }

    bool operator==(const Point2D &b) const { return x == b.x && y == b.y; }
};
}

template<>
struct std::hash<utils::Point2D>
{
    std::size_t operator()(const utils::Point2D &p) const noexcept
    {
        return std::hash<int>{}(p.x) ^ std::hash<int>{}(p.y);
    }
};