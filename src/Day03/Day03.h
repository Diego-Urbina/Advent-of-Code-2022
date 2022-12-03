#pragma once
#include <cctype>
#include <cstdint>
#include <string>
#include <vector>

static uint64_t get_bitmask(char c)
{
    uint64_t bitmask = 0;
    if (std::islower(c)) {
        bitmask = c - 'a';
    }
    else {
        bitmask = c - 'A' + 26;
    }
    return bitmask;
}

static int get_value(uint64_t bitmask)
{
    int value = 1;
    while (bitmask != 1) {
        bitmask = bitmask / 2;
        value++;
    }
    return value;
}

struct Rucksack
{
    void add_to_compartement(char c, bool to_first_compartment)
    {
        uint64_t bitmask = get_bitmask(c);
        if (to_first_compartment) {
            mCompartment1 |= 1ll << bitmask;
        }
        else {
            mCompartment2 |= 1ll << bitmask;
        }
    }

    int get_value_repeat_object() const
    {
        uint64_t repeat = mCompartment1 & mCompartment2;
        return get_value(repeat);
    }

    uint64_t get_all_items() const { return mCompartment1 | mCompartment2; }

    uint64_t mCompartment1{0};
    uint64_t mCompartment2{0};
};

class Day03
{
public:
    Day03(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<Rucksack> mRucksacks;
};
