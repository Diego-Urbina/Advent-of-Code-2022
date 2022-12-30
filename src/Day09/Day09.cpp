#include "Day09.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iterator>
#include <set>
#include <vector>
#include "../utils/format.h"
#include "../utils/string.h"

Day09::Day09(std::string execFolder) : mInputFile{execFolder + "/input/Day09.txt"}
{
    utils::format::print_title(9);
    ReadData();
}

int Day09::Puzzle1()
{
    std::vector<utils::Point2D> rope;
    rope.insert(rope.end(), 2, utils::Point2D());

    int answer = move_rope(rope);
    utils::format::print_answer(1, answer);
    return answer;
}

long long Day09::Puzzle2()
{
    std::vector<utils::Point2D> rope;
    rope.insert(rope.end(), 10, utils::Point2D());

    int answer = move_rope(rope);
    utils::format::print_answer(2, answer);
    return answer;
}

void Day09::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        auto split = utils::string::split(line, ' ');
        mMovs.push_back({split[0], std::stoi(split[1])});
    }
}

int Day09::move_rope(std::vector<utils::Point2D> &rope)
{
    utils::Point2D &head = rope.front();
    utils::Point2D &tail = rope.back();
    std::set<utils::Point2D> tailVisitedPositions{tail};

    auto move = [&](const auto &mov) {
        for (int i = 0; i < mov.second; i++) {
            move_head(head, mov.first);
            for (int j = 1; j < rope.size(); j++) {
                move_next_to(rope[j - 1], rope[j]);
            }
            tailVisitedPositions.insert(tail);
        }
    };
    std::for_each(mMovs.begin(), mMovs.end(), move);

    return tailVisitedPositions.size();
}

void Day09::move_head(utils::Point2D &head, const std::string &movement)
{
    if (movement == "U") {
        head.y++;
    }
    else if (movement == "D") {
        head.y--;
    }
    else if (movement == "L") {
        head.x--;
    }
    else if (movement == "R") {
        head.x++;
    }
}

void Day09::move_next_to(const utils::Point2D &p1, utils::Point2D &p2)
{
    if (std::abs(p1.x - p2.x) >= 2) {
        // Move next to in x-axis
        if (p1.x > p2.x) p2.x++;
        else p2.x--;

        if (std::abs(p1.y - p2.y) >= 2) {
            if (p1.y > p2.y) p2.y++;
            else p2.y--;
        }
        else {
            p2.y = p1.y;
        }
    }
    else if (std::abs(p1.y - p2.y) >= 2) {
        // Move next to in y-axis
        if (p1.y > p2.y) p2.y++;
        else p2.y--;
        p2.x = p1.x;
    }
}
