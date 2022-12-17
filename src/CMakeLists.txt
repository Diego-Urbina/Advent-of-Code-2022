project(aoc2022)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    Day01/Day01.cpp
    Day02/Day02.cpp
    Day03/Day03.cpp
    Day04/Day04.cpp
    Day05/Day05.cpp
    Day06/Day06.cpp
    Day07/Day07.cpp
    Day08/Day08.cpp
    Day09/Day09.cpp
    Day10/Day10.cpp
    Day11/Day11.cpp
    Day12/Day12.cpp
    Day13/Day13.cpp
    Day14/Day14.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    ${CONAN_LIBS}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_CURRENT_SOURCE_DIR}/input $<TARGET_FILE_DIR:${PROJECT_NAME}>/input)
