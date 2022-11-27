#include <gtest/gtest.h>

#define FMT_HEADER_ONLY
#include <fmt/core.h>

TEST(TestExample, Test1)
{
    auto s = fmt::format("{} * {} = {}", 6, 7, 6 * 7);
    EXPECT_EQ(s, "6 * 7 = 42");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}