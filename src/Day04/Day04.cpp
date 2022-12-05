#include "Day04.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../utils/format.h"
#include "../utils/string.h"

Day04::Day04(std::string execFolder) : mInputFile{execFolder + "/input/Day04.txt"}
{
    utils::format::print_title(4);
    ReadData();
}

int Day04::Puzzle1()
{
    int answer = 0;

    for (const auto &sectionPair : mSectionPairs) {
        if (sectionPair.first.contains(sectionPair.second) ||
            sectionPair.second.contains(sectionPair.first)) {
            answer++;
        }
    }
    utils::format::print_answer(1, answer);
    return answer;
}

int Day04::Puzzle2()
{
    int answer = 0;

    for (const auto &sectionPair : mSectionPairs) {
        if (sectionPair.first.overlap(sectionPair.second) ||
            sectionPair.second.overlap(sectionPair.first)) {
            answer++;
        }
    }
    utils::format::print_answer(2, answer);
    return answer;
}

void Day04::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        std::vector<std::string> sections = utils::string::split(line, ',');
        std::vector<std::string> section1 = utils::string::split(sections[0], '-');
        std::vector<std::string> section2 = utils::string::split(sections[1], '-');

        mSectionPairs.push_back({{std::stoi(section1[0]), std::stoi(section1[1])},
                                 {std::stoi(section2[0]), std::stoi(section2[1])}});
    }
}
