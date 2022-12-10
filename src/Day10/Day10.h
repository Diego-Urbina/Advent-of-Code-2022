#pragma once
#include <string>
#include <vector>

const std::string IDLE = "idle";
const std::string NOOP = "noop";
const std::string ADDX = "addx";

struct Instruction
{
    std::string name;
    int duration;
    int start_cycle;
    int value;
};

class Cpu
{
public:
    Cpu();
    void execute_instruction();
    void add_idle();
    void add_noop();
    void add_addx(int value);
    void enable_draw() { m_enable_draw = true; };
    int answer() const;

private:
    void add_instruction(Instruction &&instruction);
    void store_value_register();
    void draw_pixel();

    int m_cycle;
    Instruction m_current_instruction;
    int m_register_x;

    bool m_enable_draw{false};

    std::vector<int> m_markers{20, 60, 100, 140, 180, 220};
    std::vector<int> m_values;
};

class Day10
{
public:
    Day10(std::string path);
    int Puzzle1();
    void Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<std::string> mInstructions;
};
