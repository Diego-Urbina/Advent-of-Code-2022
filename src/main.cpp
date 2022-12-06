#include <filesystem>
#include <iostream>

#include "Day01/Day01.h"
#include "Day02/Day02.h"
#include "Day03/Day03.h"
#include "Day04/Day04.h"
#include "Day05/Day05.h"
#include "Day06/Day06.h"

int main(int argc, char *argv[])
{
    auto execFolder = std::filesystem::canonical(std::filesystem::path(argv[0])).parent_path();

    Day01 day01(execFolder);
    day01.Puzzle1();
    day01.Puzzle2();

    Day02 day02(execFolder);
    day02.Puzzle1();
    day02.Puzzle2();

    Day03 day03(execFolder);
    day03.Puzzle1();
    day03.Puzzle2();

    Day04 day04(execFolder);
    day04.Puzzle1();
    day04.Puzzle2();

    Day05 day05(execFolder);
    day05.Puzzle1();
    day05.Puzzle2();

    Day06 day06(execFolder);
    day06.Puzzle1();
    day06.Puzzle2();

    return 0;
}
