#pragma once
#include <string>
#include <vector>

class Day14
{
public:
    Day14(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    void add_rock_line(int row1, int col1, int row2, int col2);
    void insert_void_row();
    void insert_floor_row();
    void print_map() const;

    /**
     * Returns true if the grain of sand comes to rest
     */
    bool throw_sand_to_the_void();

    bool throw_sand_to_the_floor();

    std::string mInputFile;

    std::vector<std::vector<char>> mMap;
    int mMinRow;
    int mMaxRow;
    int mMinCol;
    int mMaxCol;
};
