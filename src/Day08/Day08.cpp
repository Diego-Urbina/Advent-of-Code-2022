#include "Day08.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include "../utils/format.h"

Day08::Day08(std::string execFolder) : mInputFile{execFolder + "/input/Day08.txt"}
{
    utils::format::print_title(8);
    ReadData();
}

int Day08::Puzzle1()
{
    int answer = 0;

    int rows = mTrees.size();
    int cols = mTrees[0].size();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (is_visible(row, col)) {
                answer++;
            }
        }
    }

    utils::format::print_answer(1, answer);
    return answer;
}

int Day08::Puzzle2()
{
    int answer = 0;
    int rows = mTrees.size();
    int cols = mTrees[0].size();
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            answer = std::max(answer, scenic_score(row, col));
        }
    }

    utils::format::print_answer(2, answer);
    return answer;
}

void Day08::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        std::vector<int> row;
        row.reserve(line.size());
        std::for_each(line.cbegin(), line.cend(), [&](char c) { row.push_back(c - '0'); });
        mTrees.push_back(row);
    }
}

bool Day08::is_visible(int row, int col)
{
    int rows = mTrees.size();
    int cols = mTrees[0].size();

    if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) return true;

    int tree = mTrees[row][col];

    if (std::all_of(mTrees[row].cbegin(), mTrees[row].cbegin() + col,
                    [=](int t) { return t < tree; }))
        return true;

    if (std::all_of(mTrees[row].cbegin() + col + 1, mTrees[row].cend(),
                    [=](int t) { return t < tree; }))
        return true;

    if (std::all_of(mTrees.cbegin(), mTrees.cbegin() + row,
                    [=](const auto &row) { return row[col] < tree; }))
        return true;

    if (std::all_of(mTrees.cbegin() + row + 1, mTrees.cend(),
                    [=](const auto &row) { return row[col] < tree; }))
        return true;

    return false;
}

int Day08::scenic_score(int row, int col)
{
    int tree = mTrees[row][col];

    // to top
    int to_top = 0;
    for (int r = row - 1; r >= 0; r--) {
        to_top++;
        if (mTrees[r][col] >= tree) break;
    }

    // to bottom
    int to_bottom = 0;
    for (int r = row + 1; r < mTrees.size(); r++) {
        to_bottom++;
        if (mTrees[r][col] >= tree) break;
    }

    // to left
    int to_left = 0;
    for (int c = col - 1; c >= 0; c--) {
        to_left++;
        if (mTrees[row][c] >= tree) break;
    }

    // to right
    int to_right = 0;
    for (int c = col + 1; c < mTrees[0].size(); c++) {
        to_right++;
        if (mTrees[row][c] >= tree) break;
    }

    return to_top * to_bottom * to_left * to_right;
}
