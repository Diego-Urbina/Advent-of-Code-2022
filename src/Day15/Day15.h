#pragma once
#include <string>
#include <utility>
#include "../utils/interval.h"
#include "../utils/point2d.h"

class Sensor
{
public:
    Sensor(const utils::Point2D &position, const utils::Point2D &beacon);

    int get_manhattan() const;

    utils::Interval get_interval_covered_horizontal(int y) const;

    utils::Interval get_interval_covered_vertical(int x) const;

    const utils::Point2D &get_sensor_position() const;
    const utils::Point2D &get_beacon_position() const;

private:
    int distance(const utils::Point2D &p1, const utils::Point2D &p2) const;

    utils::Point2D m_position;
    utils::Point2D m_beacon;

    utils::Point2D m_top;
    utils::Point2D m_bottom;
    utils::Point2D m_left;
    utils::Point2D m_right;
};

class Day15
{
public:
    Day15(std::string path);
    int Puzzle1(bool test = false);
    long long Puzzle2(bool test = false);

private:
    void ReadData();

    std::string mInputFile;
    std::vector<Sensor> mSensors;
};
