#pragma once
#include <functional>

namespace utils
{
struct Interval
{
    bool contains(const Interval &i) const { return low <= i.low && high >= i.high; }

    bool overlap(const Interval &i) const { return low <= i.high && i.low <= high; }

    Interval join(const Interval &i) const
    {
        return {std::min(low, i.low), std::max(high, i.high)};
    }

    bool empty() const { return low > high; }

    int size() const { return high - low + 1; }

    bool operator<(const Interval &b) const
    {
        return low < b.low || (low == b.low && high < b.high);
    }

    bool operator==(const Interval &b) const { return low == b.low && high == b.high; }

    int low{1};
    int high{0};
};
}

template<>
struct std::hash<utils::Interval>
{
    std::size_t operator()(const utils::Interval &p) const noexcept
    {
        return std::hash<int>{}(p.low) ^ std::hash<int>{}(p.high);
    }
};