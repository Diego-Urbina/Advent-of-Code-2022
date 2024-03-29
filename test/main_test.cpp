#include <gtest/gtest.h>

#include <string>

#include "../src/Day01/Day01.h"
#include "../src/Day02/Day02.h"
#include "../src/Day03/Day03.h"
#include "../src/Day04/Day04.h"
#include "../src/Day05/Day05.h"
#include "../src/Day06/Day06.h"
#include "../src/Day07/Day07.h"
#include "../src/Day08/Day08.h"
#include "../src/Day09/Day09.h"
#include "../src/Day10/Day10.h"
#include "../src/Day11/Day11.h"
#include "../src/Day12/Day12.h"
#include "../src/Day13/Day13.h"
#include "../src/Day14/Day14.h"
#include "../src/Day15/Day15.h"
#include "../src/Day16/Day16.h"

TEST(Day01, Puzzle1)
{
    Day01 day01(".");
    EXPECT_EQ(day01.Puzzle1(), 24000);
}

TEST(Day01, Puzzle2)
{
    Day01 day01(".");
    EXPECT_EQ(day01.Puzzle2(), 45000);
}

TEST(Day02, Puzzle1)
{
    Day02 day02(".");
    EXPECT_EQ(day02.Puzzle1(), 15);
}

TEST(Day02, Puzzle2)
{
    Day02 day02(".");
    EXPECT_EQ(day02.Puzzle2(), 12);
}

TEST(Day03, Puzzle1)
{
    Day03 day03(".");
    EXPECT_EQ(day03.Puzzle1(), 157);
}

TEST(Day03, Puzzle2)
{
    Day03 day03(".");
    EXPECT_EQ(day03.Puzzle2(), 70);
}

TEST(Day04, Puzzle1)
{
    Day04 day04(".");
    EXPECT_EQ(day04.Puzzle1(), 2);
}

TEST(Day04, Puzzle2)
{
    Day04 day04(".");
    EXPECT_EQ(day04.Puzzle2(), 4);
}

TEST(Day05, Puzzle1)
{
    Day05 day05(".");
    EXPECT_EQ(day05.Puzzle1(), "CMZ");
}

TEST(Day05, Puzzle2)
{
    Day05 day05(".");
    EXPECT_EQ(day05.Puzzle2(), "MCD");
}

TEST(Day06, Puzzle1)
{
    Day06 day06(".");
    EXPECT_EQ(day06.Puzzle1(), 7);
}

TEST(Day06, Puzzle2)
{
    Day06 day06(".");
    EXPECT_EQ(day06.Puzzle2(), 19);
}

TEST(Day07, Puzzle1)
{
    Day07 day07(".");
    EXPECT_EQ(day07.Puzzle1(), 95437);
}

TEST(Day07, Puzzle2)
{
    Day07 day07(".");
    EXPECT_EQ(day07.Puzzle2(), 24933642);
}

TEST(Day08, Puzzle1)
{
    Day08 day08(".");
    EXPECT_EQ(day08.Puzzle1(), 21);
}

TEST(Day08, Puzzle2)
{
    Day08 day08(".");
    EXPECT_EQ(day08.Puzzle2(), 8);
}

TEST(Day09, Puzzle1)
{
    Day09 day09(".");
    EXPECT_EQ(day09.Puzzle1(), 13);
}

TEST(Day09, Puzzle2)
{
    Day09 day09(".");
    EXPECT_EQ(day09.Puzzle2(), 1);
}

TEST(Day10, Puzzle1)
{
    Day10 day10(".");
    EXPECT_EQ(day10.Puzzle1(), 13140);
}

TEST(Day11, Puzzle1)
{
    Day11 day11(".");
    EXPECT_EQ(day11.Puzzle1(true), 10605);
}

TEST(Day11, Puzzle2)
{
    Day11 day11(".");
    EXPECT_EQ(day11.Puzzle2(true), 2713310158);
}

TEST(Day12, Puzzle1)
{
    Day12 day12(".");
    EXPECT_EQ(day12.Puzzle1(), 31);
}

TEST(Day12, Puzzle2)
{
    Day12 day12(".");
    EXPECT_EQ(day12.Puzzle2(), 29);
}

TEST(Day13, Puzzle1)
{
    Day13 day13(".");
    EXPECT_EQ(day13.Puzzle1(), 13);
}

TEST(Day13, Puzzle2)
{
    Day13 day13(".");
    EXPECT_EQ(day13.Puzzle2(), 140);
}

TEST(Day14, Puzzle1)
{
    Day14 day14(".");
    EXPECT_EQ(day14.Puzzle1(), 24);
}

TEST(Day14, Puzzle2)
{
    Day14 day14(".");
    EXPECT_EQ(day14.Puzzle2(), 93);
}

TEST(Day15, Puzzle1)
{
    Day15 day15(".");
    EXPECT_EQ(day15.Puzzle1(true), 26);
}

TEST(Day15, Puzzle2)
{
    Day15 day15(".");
    EXPECT_EQ(day15.Puzzle2(true), 56000011);
}

TEST(Day16, Puzzle1)
{
    Day16 day16(".");
    EXPECT_EQ(day16.Puzzle1(), 1651);
}

TEST(Day16, Puzzle2)
{
    Day16 day16(".");
    EXPECT_EQ(day16.Puzzle2(), 1707);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
