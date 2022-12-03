#include <gtest/gtest.h>

#include <filesystem>
#include <string>

#include "../src/Day01/Day01.h"
#include "../src/Day02/Day02.h"

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

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
