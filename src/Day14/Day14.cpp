#include "Day14.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../utils/format.h"
#include "../utils/string.h"

constexpr int START_ROW = 0;
constexpr int START_COL = 500;
constexpr int MAX_WIDTH = 1000;
constexpr char AIR = ' ';
constexpr char ROCK = '#';
constexpr char SAND = '*';

Day14::Day14(std::string execFolder) : mInputFile{execFolder + "/input/Day14.txt"}
{
    utils::format::print_title(14);
}

int Day14::Puzzle1()
{
    ReadData();
    insert_void_row();

    int answer = 0;

    while (throw_sand_to_the_void()) {
        answer++;
    }

    utils::format::print_answer(1, answer);
    return answer;
}

int Day14::Puzzle2()
{
    ReadData();
    insert_void_row();
    insert_floor_row();

    int answer = 0;

    while (throw_sand_to_the_floor()) {
        answer++;
    }

    utils::format::print_answer(2, answer);
    return answer;
}

void Day14::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    mMinRow = 99999999;
    mMaxRow = 0;
    mMinCol = 99999999;
    mMaxCol = 0;

    mMap.clear();
    for (std::string line; std::getline(ifs, line);) {
        auto points = utils::string::split(line, " -> ");
        for (int i = 1; i < points.size(); i++) {
            auto p1 = utils::string::split(points[i - 1], ',');
            auto p2 = utils::string::split(points[i], ',');
            int col1 = std::stoi(p1[0]);
            int row1 = std::stoi(p1[1]);
            int col2 = std::stoi(p2[0]);
            int row2 = std::stoi(p2[1]);

            mMinRow = std::min(std::min(mMinRow, row1), row2);
            mMaxRow = std::max(std::max(mMaxRow, row1), row2);
            mMinCol = std::min(std::min(mMinCol, col1), col2);
            mMaxCol = std::max(std::max(mMaxCol, col1), col2);

            add_rock_line(row1, col1, row2, col2);
        }
    }
}

void Day14::add_rock_line(int row1, int col1, int row2, int col2)
{
    while (mMap.size() <= row1 || mMap.size() <= row2) {
        mMap.emplace_back(MAX_WIDTH, AIR);
    }

    if (row1 == row2) {
        for (int c = std::min(col1, col2); c <= std::max(col1, col2); c++) {
            mMap[row1][c] = ROCK;
        }
    }
    else if (col1 == col2) {
        for (int r = std::min(row1, row2); r <= std::max(row1, row2); r++) {
            mMap[r][col1] = ROCK;
        }
    }
}

void Day14::insert_void_row()
{
    mMap.emplace_back(MAX_WIDTH, AIR);
}

void Day14::insert_floor_row()
{
    mMap.emplace_back(MAX_WIDTH, ROCK);
}

void Day14::print_map() const
{
    for (int r = 0; r <= mMaxRow; r++) {
        for (int c = mMinCol; c <= mMaxCol; c++) {
            std::cout << mMap[r][c];
        }
        std::cout << std::endl;
    }
}

bool Day14::throw_sand_to_the_void()
{
    int row_sand = START_ROW;
    int col_sand = START_COL;

    while (row_sand <= mMaxRow) {
        char below = mMap[row_sand + 1][col_sand];
        char below_l = mMap[row_sand + 1][col_sand - 1];
        char below_r = mMap[row_sand + 1][col_sand + 1];

        if (below == AIR) {
            row_sand++;
        }
        else {
            if (below_l == AIR) {
                row_sand++;
                col_sand--;
            }
            else if (below_r == AIR) {
                row_sand++;
                col_sand++;
            }
            else {
                mMap[row_sand][col_sand] = SAND;
                return true;
            }
        }
    }

    return false;
}

bool Day14::throw_sand_to_the_floor()
{
    int row_sand = START_ROW;
    int col_sand = START_COL;

    if (mMap[START_ROW][START_COL] == SAND) return false;

    while (row_sand <= mMaxRow + 1) {
        char below = mMap[row_sand + 1][col_sand];
        char below_l = mMap[row_sand + 1][col_sand - 1];
        char below_r = mMap[row_sand + 1][col_sand + 1];

        if (below == AIR) {
            row_sand++;
        }
        else {
            if (below_l == AIR) {
                row_sand++;
                col_sand--;
            }
            else if (below_r == AIR) {
                row_sand++;
                col_sand++;
            }
            else {
                mMap[row_sand][col_sand] = SAND;
                break;
            }
        }
    }

    return true;
}