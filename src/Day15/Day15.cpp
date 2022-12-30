#include "Day15.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <set>
#include <vector>
#include "../utils/format.h"
#include "../utils/string.h"

Sensor::Sensor(const utils::Point2D &position, const utils::Point2D &beacon) :
    m_position{position}, m_beacon{beacon}
{
    m_top = {m_position.x, m_position.y - get_manhattan()};
    m_bottom = {m_position.x, m_position.y + get_manhattan()};
    m_left = {m_position.x - get_manhattan(), m_position.y};
    m_right = {m_position.x + get_manhattan(), m_position.y};
}

int Sensor::get_manhattan() const
{
    return distance(m_position, m_beacon);
}

utils::Interval Sensor::get_interval_covered_horizontal(int y) const
{
    utils::Interval ret;

    int horizontal_rest = get_manhattan() - std::abs(m_position.y - y);
    if (horizontal_rest >= 0) {
        ret.low = m_position.x - horizontal_rest;
        ret.high = m_position.x + horizontal_rest;
    }

    return ret;
}

utils::Interval Sensor::get_interval_covered_vertical(int x) const
{
    utils::Interval ret;

    int vertical_rest = get_manhattan() - std::abs(m_position.x - x);
    if (vertical_rest >= 0) {
        ret.low = m_position.y - vertical_rest;
        ret.high = m_position.y + vertical_rest;
    }

    return ret;
}

const utils::Point2D &Sensor::get_sensor_position() const
{
    return m_position;
}

const utils::Point2D &Sensor::get_beacon_position() const
{
    return m_beacon;
}

int Sensor::distance(const utils::Point2D &p1, const utils::Point2D &p2) const
{
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

Day15::Day15(std::string execFolder) : mInputFile{execFolder + "/input/Day15.txt"}
{
    utils::format::print_title(15);
    ReadData();
}

int Day15::Puzzle1(bool test)
{
    int y_target = !test ? 2'000'000 : 10;

    std::vector<utils::Interval> covered_intervals;
    std::for_each(mSensors.cbegin(), mSensors.cend(), [&](const Sensor &s) {
        auto i = s.get_interval_covered_horizontal(y_target);
        if (!i.empty()) {
            covered_intervals.push_back(i);
        }
    });

    int answer = 0;
    if (covered_intervals.size() > 0) {
        std::sort(covered_intervals.begin(), covered_intervals.end());
        std::vector<utils::Interval> result{covered_intervals.front()};

        for (int i = 1; i < covered_intervals.size(); i++) {
            if (covered_intervals[i].overlap(result.back())) {
                auto join = covered_intervals[i].join(result.back());
                result.pop_back();
                result.push_back(join);
            }
        }

        answer = std::accumulate(result.cbegin(), result.cend(), 0,
                                 [](int a, const auto &b) { return a + b.size(); });

        std::set<utils::Point2D> visited_beacons;
        for (const auto &sensor : mSensors) {
            if (sensor.get_beacon_position().y == y_target &&
                std::any_of(result.begin(), result.end(), [&](const auto &interval) {
                    return interval.low <= sensor.get_beacon_position().x &&
                           sensor.get_beacon_position().x <= interval.high;
                })) {
                if (visited_beacons.count(sensor.get_beacon_position()) == 0) {
                    answer--;
                    visited_beacons.insert(sensor.get_beacon_position());
                }
            }
        }
    }

    utils::format::print_answer(1, answer);
    return answer;
}

long long Day15::Puzzle2(bool test)
{
    int space = !test ? 4'000'000 : 20;

    utils::Point2D ret;
    for (int y = 0; y <= space; y++) {
        std::vector<utils::Interval> covered_intervals;
        std::for_each(mSensors.cbegin(), mSensors.cend(), [&](const Sensor &s) {
            auto i = s.get_interval_covered_horizontal(y);
            if (!i.empty()) {
                covered_intervals.push_back(i);
            }
        });

        if (covered_intervals.size() > 0) {
            std::sort(covered_intervals.begin(), covered_intervals.end());
            std::vector<utils::Interval> result{covered_intervals.front()};

            for (int i = 1; i < covered_intervals.size(); i++) {
                if (covered_intervals[i].overlap(result.back())) {
                    auto join = covered_intervals[i].join(result.back());
                    result.pop_back();
                    result.push_back(join);
                }
            }

            int acc = std::accumulate(result.cbegin(), result.cend(), 0,
                                      [](int a, const auto &b) { return a + b.size(); });

            if (acc < space) {
                ret.y = y;
                int blank = 0;
                for (const auto &interval : result) {
                    if (interval.low > blank) {
                        break;
                    }
                    else {
                        blank = interval.high + 1;
                    }
                }
                ret.x = blank;
                break;
            }
        }
    }

    long long answer = ret.x * 4000000ll + ret.y;
    utils::format::print_answer(2, answer);
    return answer;
}

void Day15::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);
    for (std::string line; std::getline(ifs, line);) {
        auto split = utils::string::split(line, ' ');
        int s_x = std::stoi(split[2].substr(2, split[2].size() - 3));
        int s_y = std::stoi(split[3].substr(2, split[3].size() - 3));
        int b_x = std::stoi(split[8].substr(2, split[8].size() - 3));
        int b_y = std::stoi(split[9].substr(2, split[9].size() - 2));
        mSensors.push_back({{s_x, s_y}, {b_x, b_y}});
    }
}
