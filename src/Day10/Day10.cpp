#include "Day10.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include "../utils/format.h"
#include "../utils/string.h"

Day10::Day10(std::string execFolder) : mInputFile{execFolder + "/input/Day10.txt"}
{
    utils::format::print_title(10);
    ReadData();
}

int Day10::Puzzle1()
{
    Cpu cpu;
    for (const auto &instruction : mInstructions) {
        auto inst = utils::string::split(instruction, ' ');
        if (inst[0] == "noop") {
            cpu.add_noop();
        }
        else if (inst[0] == "addx") {
            cpu.add_addx(std::stoi(inst[1]));
        }
        cpu.execute_instruction();
    }

    int answer = cpu.answer();
    utils::format::print_answer(1, answer);
    return answer;
}

void Day10::Puzzle2()
{
    utils::format::print_answer(2, "");
    Cpu cpu;
    cpu.enable_draw();
    for (const auto &instruction : mInstructions) {
        auto inst = utils::string::split(instruction, ' ');
        if (inst[0] == "noop") {
            cpu.add_noop();
        }
        else if (inst[0] == "addx") {
            cpu.add_addx(std::stoi(inst[1]));
        }
        cpu.execute_instruction();
    }
    std::cout << std::endl;
}

void Day10::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {
        mInstructions.push_back(line);
    }
}

Cpu::Cpu() : m_cycle{0}, m_register_x{1}
{
    add_idle();
}

void Cpu::add_instruction(Instruction &&instruction)
{
    m_current_instruction = instruction;
}

void Cpu::execute_instruction()
{
    while (m_current_instruction.name != IDLE) {
        m_cycle++;

        // Store values
        store_value_register();

        // Draw pixels
        if (m_enable_draw) draw_pixel();

        if (m_current_instruction.duration == m_cycle - m_current_instruction.start_cycle) {
            // Exec
            if (m_current_instruction.name == NOOP) {}
            else if (m_current_instruction.name == ADDX) {
                m_register_x += m_current_instruction.value;
            }
            add_idle();
        }
    }
}

void Cpu::add_idle()
{
    add_instruction({IDLE, 0, m_cycle, 0});
}

void Cpu::add_noop()
{
    add_instruction({NOOP, 1, m_cycle, 0});
}

void Cpu::add_addx(int value)
{
    add_instruction({ADDX, 2, m_cycle, value});
}

void Cpu::store_value_register()
{
    if (std::find(m_markers.cbegin(), m_markers.cend(), m_cycle) != m_markers.cend()) {
        m_values.push_back(m_cycle * m_register_x);
    }
}

void Cpu::draw_pixel()
{
    int pixel = (m_cycle - 1) % 40;
    if (m_cycle > 1 && pixel == 0) {
        std::cout << std::endl;
    }

    if (m_register_x - 1 <= pixel && pixel <= m_register_x + 1) std::cout << '#';
    else std::cout << ' ';
}

int Cpu::answer() const
{
    return std::accumulate(m_values.cbegin(), m_values.cend(), 0);
}