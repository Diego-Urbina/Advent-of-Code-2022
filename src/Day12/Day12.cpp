#include "Day12.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
#include "../utils/format.h"

Day12::Day12(std::string execFolder) : mInputFile{execFolder + "/input/Day12.txt"}
{
    utils::format::print_title(12);
}

int Day12::Puzzle1()
{
    ReadData();

    for (int row = 0; row < mMap.size(); row++) {
        for (int col = 0; col < mMap[row].size(); col++) {
            if (mMap[row][col] == 'S') {
                mStart = {row, col};
                mMap[row][col] = 'a';
            }
            if (mMap[row][col] == 'E') {
                mEnd = {row, col};
                mMap[row][col] = 'z';
            }
        }
    }

    std::queue<std::pair<int, int>> nodes;
    nodes.push(mStart);
    mVisited[mStart.first][mStart.second] = 0;
    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();

        // If we reach the end, we should keep searching for a shorter path
        if (node == mEnd) continue;

        for (auto neighbor : get_neighbors(node)) {
            if (in_boundaries(neighbor)) {
                if (mMap[neighbor.first][neighbor.second] <= mMap[node.first][node.second] + 1) {
                    if (mVisited[neighbor.first][neighbor.second] >
                        mVisited[node.first][node.second] + 1) {
                        // Maybe it's the first time that we see this node,
                        // or maybe we've just found a better path
                        nodes.push(neighbor);
                        mVisited[neighbor.first][neighbor.second] =
                          mVisited[node.first][node.second] + 1;
                    }
                }
            }
        }
    }

    int answer = mVisited[mEnd.first][mEnd.second];
    utils::format::print_answer(1, answer);
    return answer;
}

int Day12::Puzzle2()
{
    ReadData();

    // Now, we start in the 'E' node and looking paths for every 'a' node
    std::vector<std::pair<int, int>> ends;
    for (int row = 0; row < mMap.size(); row++) {
        for (int col = 0; col < mMap[row].size(); col++) {
            if (mMap[row][col] == 'S' || mMap[row][col] == 'a') {
                ends.emplace_back(row, col);
                mMap[row][col] = 'a';
            }
            if (mMap[row][col] == 'E') {
                mStart = {row, col};
                mMap[row][col] = 'z';
            }
        }
    }

    std::queue<std::pair<int, int>> nodes;
    nodes.push(mStart);
    mVisited[mStart.first][mStart.second] = 0;
    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();

        for (auto neighbor : get_neighbors(node)) {
            if (in_boundaries(neighbor)) {
                if (mMap[neighbor.first][neighbor.second] >= mMap[node.first][node.second] - 1) {
                    if (mVisited[neighbor.first][neighbor.second] >
                        mVisited[node.first][node.second] + 1) {
                        // Maybe it's the first time that we see this node,
                        // or maybe we've just found a better path
                        nodes.push(neighbor);
                        mVisited[neighbor.first][neighbor.second] =
                          mVisited[node.first][node.second] + 1;
                    }
                }
            }
        }
    }

    std::sort(ends.begin(), ends.end(), [&](const auto &p1, const auto &p2) {
        return mVisited[p1.first][p1.second] < mVisited[p2.first][p2.second];
    });

    auto &n = ends[0];
    int answer = mVisited[n.first][n.second];
    utils::format::print_answer(2, answer);
    return answer;
}

void Day12::ReadData()
{
    mMap.clear();
    mVisited.clear();
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        mMap.push_back(line);
        mVisited.emplace_back(line.size(), std::numeric_limits<int>::max());
    }
}
std::vector<std::pair<int, int>> Day12::get_neighbors(const std::pair<int, int> node) const
{
    std::vector<std::pair<int, int>> neighbors;

    neighbors.emplace_back(node.first + 1, node.second);
    neighbors.emplace_back(node.first - 1, node.second);
    neighbors.emplace_back(node.first, node.second + 1);
    neighbors.emplace_back(node.first, node.second - 1);

    return neighbors;
}

bool Day12::in_boundaries(std::pair<int, int> node) const
{
    return node.first >= 0 && node.first < mMap.size() && node.second >= 0 &&
           node.second < mMap[0].size();
}
