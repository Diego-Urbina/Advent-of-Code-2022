#include "Day01.h"
#include <iostream>
#include <fstream>
#include "../utils/format_utils.h"

Day01::Day01(std::string execFolder) : mInputFile{execFolder + "/input/Day01.txt"}
{
    utils::format::print_title(1);
    ReadData();
}

int Day01::Puzzle1()
{
    int answer = mElfs.top()->mCalories;

    utils::format::print_answer(1, answer);
    return answer;
}

int Day01::Puzzle2()
{
    int answer = 0;
    for (int i = 1; i <= 3; ++i) {
        answer += mElfs.top()->mCalories;
        mElfs.pop();
    }

    utils::format::print_answer(2, answer);
    return answer;
}

void Day01::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    std::unique_ptr<Elf> elf = std::make_unique<Elf>();
    for (std::string calories; std::getline(ifs, calories);) {
        if (!calories.empty()) {
            elf->mCalories += std::stoi(calories);
        }
        else {
            mElfs.push(std::move(elf));
            elf = std::make_unique<Elf>();
        }
    }
    mElfs.push(std::move(elf));
}
