#include "Day13.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iterator>
#include <stack>
#include <string>
#include <variant>
#include <vector>
#include "../utils/format.h"

Day13::Day13(std::string execFolder) : mInputFile{execFolder + "/input/Day13.txt"}
{
    utils::format::print_title(13);
    ReadData();
}

int Day13::Puzzle1()
{
    int answer = 0;
    for (int i = 0; i < mLists.size(); i += 2) {
        if (mLists[i] < mLists[i + 1]) {
            answer += (i / 2) + 1;
        }
    }
    utils::format::print_answer(1, answer);
    return answer;
}

int Day13::Puzzle2()
{
    std::vector<Node> divider1 = std::vector<Node>{std::vector<Node>{{2}}};
    std::vector<Node> divider2 = std::vector<Node>{std::vector<Node>{{6}}};
    mLists.push_back(divider1);
    mLists.push_back(divider2);

    std::sort(mLists.begin(), mLists.end());

    auto it1 = std::find(mLists.begin(), mLists.end(), divider1);
    auto it2 = std::find(mLists.begin(), mLists.end(), divider2);

    int answer =
      (std::distance(mLists.begin(), it1) + 1) * (std::distance(mLists.begin(), it2) + 1);
    utils::format::print_answer(2, answer);
    return answer;
}

void Day13::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        std::stack<std::vector<Node>> stack;
        std::string number;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '[') {
                std::vector<Node> list;
                stack.push(list);
            }
            else if (line[i] == ']') {
                auto list = stack.top();
                stack.pop();
                if (!number.empty()) {
                    list.push_back({std::stoi(number)});
                    number.clear();
                }
                if (!stack.empty()) {
                    stack.top().push_back({list});
                }
                else {
                    // Should be the last char
                    assert(i == line.size() - 1);
                    mLists.push_back(list);
                }
            }
            else if (line[i] == ',') {
                if (!number.empty()) {
                    stack.top().push_back({std::stoi(number)});
                    number.clear();
                }
            }
            else {
                // Numbers
                number += line[i];
            }
        }
    }
}
