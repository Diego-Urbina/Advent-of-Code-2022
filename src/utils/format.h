#pragma once

#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <fmt/color.h>

namespace utils
{
namespace format
{
static void print_title(int day)
{
    fmt::print(fmt::emphasis::bold | fmt::emphasis::underline | fg(fmt::color::red),
               "\nDAY {:02}\n", day);
}

static void print_answer(int puzzle, long long answer)
{
    fmt::print(fg(fmt::color::green), "Puzzle {}: {}\n", puzzle, answer);
}
}
}