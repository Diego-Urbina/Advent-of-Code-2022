#include <filesystem>
#include <iostream>

#include "Day01/Day01.h"
#include "Day02/Day02.h"
#include "Day03/Day03.h"
#include "Day04/Day04.h"
#include "Day05/Day05.h"
#include "Day06/Day06.h"
#include "Day07/Day07.h"
#include "Day08/Day08.h"
#include "Day09/Day09.h"
#include "Day10/Day10.h"
#include "Day11/Day11.h"
#include "Day12/Day12.h"
#include "Day13/Day13.h"
#include "Day14/Day14.h"
#include "Day15/Day15.h"
#include "Day16/Day16.h"

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

    Day07 day07(execFolder);
    day07.Puzzle1();
    day07.Puzzle2();

    Day08 day08(execFolder);
    day08.Puzzle1();
    day08.Puzzle2();

    Day09 day09(execFolder);
    day09.Puzzle1();
    day09.Puzzle2();

    Day10 day10(execFolder);
    day10.Puzzle1();
    day10.Puzzle2();

    Day11 day11(execFolder);
    day11.Puzzle1();
    day11.Puzzle2();

    Day12 day12(execFolder);
    day12.Puzzle1();
    day12.Puzzle2();

    Day13 day13(execFolder);
    day13.Puzzle1();
    day13.Puzzle2();

    Day14 day14(execFolder);
    day14.Puzzle1();
    day14.Puzzle2();

    Day15 day15(execFolder);
    day15.Puzzle1();
    day15.Puzzle2();

    Day16 day16(execFolder);
    day16.Puzzle1();
    day16.Puzzle2();

    return 0;
}
