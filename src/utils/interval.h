#pragma once

namespace utils
{
    struct Interval
    {
        bool contains(const Interval &other) const
        {
            return this->low <= other.low && this->high >= other.high;
        }

        bool overlap(const Interval &other) const
        {
            return this->low <= other.high && other.low <= high;
        }

        int low;
        int high;
    };
}