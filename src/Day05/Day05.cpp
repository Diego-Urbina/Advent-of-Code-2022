#include "Day05.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "../utils/format.h"
#include "../utils/string.h"

Day05::Day05(std::string execFolder) : mInputFile{execFolder + "/input/Day05.txt"}
{
    utils::format::print_title(5);
}

std::string Day05::Puzzle1()
{
    std::string answer{};

    ReadData();

    for (const auto &move : mMoves) {
        // Move from-to
        for (int i = 0; i < move.quantity; i++) {
            char crate = mCrateStacks[move.from].top();
            mCrateStacks[move.from].pop();
            mCrateStacks[move.to].push(crate);
        }
    }

    // Get tops
    for (const auto &mCrateStack : mCrateStacks) {
        if (!mCrateStack.empty()) {
            answer += mCrateStack.top();
        }
    }
    utils::format::print_answer(1, answer);
    return answer;
}

std::string Day05::Puzzle2()
{
    std::string answer{};

    ReadData();

    for (const auto &move : mMoves) {
        std::stack<char> aux;
        // Move from-aux
        for (int i = 0; i < move.quantity; i++) {
            char crate = mCrateStacks[move.from].top();
            mCrateStacks[move.from].pop();
            aux.push(crate);
        }
        // Move aux-to
        for (int i = 0; i < move.quantity; i++) {
            char crate = aux.top();
            aux.pop();
            mCrateStacks[move.to].push(crate);
        }
    }

    // Get tops
    for (const auto &mCrateStack : mCrateStacks) {
        if (!mCrateStack.empty()) {
            answer += mCrateStack.top();
        }
    }
    utils::format::print_answer(2, answer);
    return answer;
}

void Day05::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    bool readingStacks = true;
    mCrateStacks.clear();
    mMoves.clear();
    std::vector<std::string> auxCrates;
    for (std::string line; std::getline(ifs, line);) {
        if (line.empty()) {
            readingStacks = false;

            for (int i = auxCrates.size() - 2; i >= 0; i--) {
                for (int j = 0; j < auxCrates[i].size(); j++) {
                    if (j >= mCrateStacks.size()) {
                        mCrateStacks.emplace_back();
                    }
                    if (std::isalpha(auxCrates[i][j])) {
                        mCrateStacks[j].push(auxCrates[i][j]);
                    }
                }
            }

            continue;
        }

        if (readingStacks) {
            std::string crates{};
            for (int i = 1; i < line.size(); i = i + 4) {
                crates += line[i];
            }
            auxCrates.push_back(crates);
        }
        else {
            auto moveSplit = utils::string::split(line, ' ');
            // subtracts 1 to from and to in order to use zero-indexed vectors
            mMoves.push_back(
              {std::stoi(moveSplit[1]), std::stoi(moveSplit[3]) - 1, std::stoi(moveSplit[5]) - 1});
        }
    }
}
