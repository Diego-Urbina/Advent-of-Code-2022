#include <iostream>

#define FMT_HEADER_ONLY
#include <fmt/core.h>

int main()
{
    std::cout << "HelloWorld from std\n";
    fmt::print("HelloWorld from fmt\n");

    return 0;
}