add_executable(
    aoc2022_test
    main_test.cpp
)

target_link_libraries(
    aoc2022_test
    ${CONAN_LIBS}
)

include(GoogleTest)
gtest_discover_tests(aoc2022_test)
