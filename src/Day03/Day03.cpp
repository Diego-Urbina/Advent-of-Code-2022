#include "Day03.h"
#include "iostream"
#include <fstream>
#include "../utils/format_utils.h"

Day03::Day03(std::string execFolder) : mInputFile{execFolder + "/input/Day03.txt"}
{
    print_title(3);
    ReadData();
}

int Day03::Puzzle1()
{
    int answer = 0;

    for (const auto &rucksack : mRucksacks) {
        answer += rucksack.get_value_repeat_object();
    }
    print_answer(1, answer);
    return answer;
}

int Day03::Puzzle2()
{
    int answer = 0;

    for (int i = 0; i < mRucksacks.size(); i = i + 3) {
        const auto &r1 = mRucksacks[i];
        const auto &r2 = mRucksacks[i + 1];
        const auto &r3 = mRucksacks[i + 2];

        uint64_t repeat_object = r1.get_all_items() & r2.get_all_items() & r3.get_all_items();
        answer += get_value(repeat_object);
    }

    print_answer(2, answer);
    return answer;
}

void Day03::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        Rucksack r;
        for (int i = 0; i < line.size(); i++) {
            r.add_to_compartement(line[i], i < line.size() / 2);
        }
        mRucksacks.push_back(r);
    }
}
