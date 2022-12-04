#include "Day02.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../utils/format.h"

constexpr int LOST_GAME = 0;
constexpr int DRAW_GAME = 3;
constexpr int WIN_GAME = 6;

Day02::Day02(std::string execFolder) : mInputFile{execFolder + "/input/Day02.txt"}
{
    utils::format::print_title(2);
    ReadData();
}

int Day02::Puzzle1()
{
    int answer = 0;

    // For each opponent's hand and own hand, return points
    std::unordered_map<char, std::unordered_map<char, int>> game_points{
      {'A', {{'X', DRAW_GAME}, {'Y', WIN_GAME}, {'Z', LOST_GAME}}},
      {'B', {{'X', LOST_GAME}, {'Y', DRAW_GAME}, {'Z', WIN_GAME}}},
      {'C', {{'X', WIN_GAME}, {'Y', LOST_GAME}, {'Z', DRAW_GAME}}}};
    std::unordered_map<char, int> hand_points{{'X', 1}, {'Y', 2}, {'Z', 3}};
    for (const auto &pair : mStrategy) {
        char op = pair.first;
        char me = pair.second;

        answer += hand_points[me];
        answer += game_points[op][me];
    }

    utils::format::print_answer(1, answer);
    return answer;
}

int Day02::Puzzle2()
{
    int answer = 0;

    // For each opponent's hand and expected result, return own hand and points
    std::unordered_map<char, std::unordered_map<char, std::pair<char, int>>> game_points{
      {'A', {{'X', {'C', LOST_GAME}}, {'Y', {'A', DRAW_GAME}}, {'Z', {'B', WIN_GAME}}}},
      {'B', {{'X', {'A', LOST_GAME}}, {'Y', {'B', DRAW_GAME}}, {'Z', {'C', WIN_GAME}}}},
      {'C', {{'X', {'B', LOST_GAME}}, {'Y', {'C', DRAW_GAME}}, {'Z', {'A', WIN_GAME}}}}};
    std::unordered_map<char, int> hand_points{{'A', 1}, {'B', 2}, {'C', 3}};
    for (const auto &pair : mStrategy) {
        char op = pair.first;
        char me = pair.second;

        answer += hand_points[game_points[op][me].first];
        answer += game_points[op][me].second;
    }

    utils::format::print_answer(2, answer);
    return answer;
}

void Day02::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        mStrategy.emplace_back(line[0], line[2]);
    }
}
