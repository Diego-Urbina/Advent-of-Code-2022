#include <filesystem>
#include <iostream>

#include "Day01/Day01.h"
#include "Day02/Day02.h"

int main(int argc, char *argv[])
{
    auto execFolder = std::filesystem::canonical(std::filesystem::path(argv[0])).parent_path();

    Day01 day01(execFolder);
    day01.Puzzle1();
    day01.Puzzle2();

    Day02 day02(execFolder);
    day02.Puzzle1();
    day02.Puzzle2();

    return 0;
}
