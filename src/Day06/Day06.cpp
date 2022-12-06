#include "Day06.h"
#include <iostream>
#include <fstream>
#include <set>
#include "../utils/format.h"

constexpr int START_PACKAGE_SIZE = 4;
constexpr int START_MESSAGE_SIZE = 14;

Day06::Day06(std::string execFolder) : mInputFile{execFolder + "/input/Day06.txt"}
{
    utils::format::print_title(6);
    ReadData();
}

int Day06::Puzzle1()
{
    int answer = find_marker(START_PACKAGE_SIZE);
    utils::format::print_answer(1, answer);
    return answer;
}

int Day06::Puzzle2()
{
    int answer = find_marker(START_MESSAGE_SIZE);
    utils::format::print_answer(2, answer);
    return answer;
}

void Day06::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);
    std::getline(ifs, mData);
}

int Day06::find_marker(int marker_size)
{
    int marker_position = 0;
    for (int i = marker_size; i < mData.size(); i++) {
        int from = i - marker_size;
        int to = i;
        std::set<char> set(mData.begin() + from, mData.begin() + to);
        if (set.size() == marker_size) {
            marker_position = i;
            break;
        }
    }
    return marker_position;
}
