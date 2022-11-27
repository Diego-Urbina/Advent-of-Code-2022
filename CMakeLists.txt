cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)