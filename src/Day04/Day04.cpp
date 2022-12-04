#include "Day04.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../utils/format.h"

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
        int commaPos = line.find(',');
        std::string firstSection = line.substr(0, commaPos);
        std::string secondSection = line.substr(commaPos + 1, line.size() - 1 - commaPos);

        int dash1Pos = firstSection.find('-');
        std::string firstSectionLow = firstSection.substr(0, dash1Pos);
        std::string firstSectionHigh =
          firstSection.substr(dash1Pos + 1, firstSection.size() - 1 - dash1Pos);

        int dash2Pos = secondSection.find('-');
        std::string secondSectionLow = secondSection.substr(0, dash2Pos);
        std::string secondSectionHigh =
          secondSection.substr(dash2Pos + 1, secondSection.size() - 1 - dash2Pos);

        mSectionPairs.push_back({{std::stoi(firstSectionLow), std::stoi(firstSectionHigh)},
                                 {std::stoi(secondSectionLow), std::stoi(secondSectionHigh)}});
    }
}
