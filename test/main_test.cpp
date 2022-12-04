#include <gtest/gtest.h>

#include <filesystem>
#include <string>

#include "../src/Day01/Day01.h"
#include "../src/Day02/Day02.h"
#include "../src/Day03/Day03.h"
#include "../src/Day04/Day04.h"

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

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
