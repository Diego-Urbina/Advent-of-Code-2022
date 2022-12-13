#include "Day11.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include "../utils/format.h"

void Monkey::add_item(Item item)
{
    mItems.push(item);
}

void Monkey::add_item(int worryLevel)
{
    Item item{worryLevel};
    mItems.push(item);
}

void Monkey::add_operation(Operation op, int argument)
{
    mOperation = op;
    mOperationArgument = argument;
}

void Monkey::add_test(int argument)
{
    mTestArgument = argument;
}

void Monkey::add_monkey_test_true(int monkey)
{
    mMonkeyTestTrue = monkey;
}

void Monkey::add_monkey_test_false(int monkey)
{
    mMonkeyTestFalse = monkey;
}

void Monkey::add_factor_worry(int factor_worry)
{
    mFactorWorry = factor_worry;
}

std::pair<Item, int> Monkey::inspect_item(bool reduce_worry)
{
    Item item = mItems.front();
    mItems.pop();

    // Update worry level acording to operation
    update_item(item);

    // Divide worry level by 3
    if (reduce_worry) item.mWorryLevel /= 3;
    // else item.mWorryLevel = item.mWorryLevel % 96577ll;
    else item.mWorryLevel = item.mWorryLevel % mFactorWorry;

    // Test worry level
    int monkey_to_pass =
      (item.mWorryLevel % mTestArgument == 0) ? mMonkeyTestTrue : mMonkeyTestFalse;

    mInspections++;

    return {item, monkey_to_pass};
}

bool Monkey::is_empty()
{
    return mItems.empty();
}

int Monkey::get_inspections() const
{
    return mInspections;
}

void Monkey::update_item(Item &item)
{
    if (mOperation == Operation::ADD) {
        item.mWorryLevel += mOperationArgument;
    }
    else if (mOperation == Operation::MULT) {
        item.mWorryLevel *= mOperationArgument;
    }
    else if (mOperation == Operation::POW) {
        item.mWorryLevel *= item.mWorryLevel;
    }
}

Day11::Day11(std::string execFolder) : mInputFile{execFolder + "/input/Day11.txt"}
{
    utils::format::print_title(11);
    ReadData();
}

int Day11::Puzzle1(bool test)
{
    if (!test) CreateMonkeyReal();
    else CreateMonkeyTest();

    for (int round = 1; round <= 20; round++) {
        for (auto &monkey : mMonkeys) {
            while (!monkey->is_empty()) {
                auto inspection_result = monkey->inspect_item(true);
                mMonkeys[inspection_result.second]->add_item(inspection_result.first);
            }
        }
    }

    std::vector<int> inspections;
    std::for_each(mMonkeys.cbegin(), mMonkeys.cend(),
                  [&](const auto &m) { inspections.push_back(m->get_inspections()); });
    std::sort(inspections.begin(), inspections.end());

    int answer = inspections[inspections.size() - 1] * inspections[inspections.size() - 2];
    utils::format::print_answer(1, answer);
    return answer;
}

long long Day11::Puzzle2(bool test)
{
    if (!test) CreateMonkeyReal();
    else CreateMonkeyTest();

    for (int round = 1; round <= 10000; round++) {
        for (auto &monkey : mMonkeys) {
            while (!monkey->is_empty()) {
                auto inspection_result = monkey->inspect_item(false);
                mMonkeys[inspection_result.second]->add_item(inspection_result.first);
            }
        }
    }

    std::vector<long long> inspections;
    std::for_each(mMonkeys.cbegin(), mMonkeys.cend(),
                  [&](const auto &m) { inspections.push_back(m->get_inspections()); });
    std::sort(inspections.begin(), inspections.end());

    long long answer = inspections[inspections.size() - 1] * inspections[inspections.size() - 2];
    utils::format::print_answer(2, answer);
    return answer;
}

void Day11::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    for (std::string line; std::getline(ifs, line);) {}
}

void Day11::CreateMonkeyTest()
{
    mMonkeys.clear();

    // Monkey 0
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(79);
    mMonkeys.back()->add_item(98);
    mMonkeys.back()->add_operation(Operation::MULT, 19);
    mMonkeys.back()->add_test(23);
    mMonkeys.back()->add_monkey_test_true(2);
    mMonkeys.back()->add_monkey_test_false(3);
    mMonkeys.back()->add_factor_worry(96577);

    // Monkey 1
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(54);
    mMonkeys.back()->add_item(65);
    mMonkeys.back()->add_item(75);
    mMonkeys.back()->add_item(74);
    mMonkeys.back()->add_operation(Operation::ADD, 6);
    mMonkeys.back()->add_test(19);
    mMonkeys.back()->add_monkey_test_true(2);
    mMonkeys.back()->add_monkey_test_false(0);
    mMonkeys.back()->add_factor_worry(96577);

    // Monkey 2
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(79);
    mMonkeys.back()->add_item(60);
    mMonkeys.back()->add_item(97);
    mMonkeys.back()->add_operation(Operation::POW, 0);
    mMonkeys.back()->add_test(13);
    mMonkeys.back()->add_monkey_test_true(1);
    mMonkeys.back()->add_monkey_test_false(3);
    mMonkeys.back()->add_factor_worry(96577);

    // Monkey 3
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(74);
    mMonkeys.back()->add_operation(Operation::ADD, 3);
    mMonkeys.back()->add_test(17);
    mMonkeys.back()->add_monkey_test_true(0);
    mMonkeys.back()->add_monkey_test_false(1);
    mMonkeys.back()->add_factor_worry(96577);
}

void Day11::CreateMonkeyReal()
{
    mMonkeys.clear();

    // Monkey 0
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(91);
    mMonkeys.back()->add_item(54);
    mMonkeys.back()->add_item(70);
    mMonkeys.back()->add_item(61);
    mMonkeys.back()->add_item(64);
    mMonkeys.back()->add_item(64);
    mMonkeys.back()->add_item(60);
    mMonkeys.back()->add_item(85);
    mMonkeys.back()->add_operation(Operation::MULT, 13);
    mMonkeys.back()->add_test(2);
    mMonkeys.back()->add_monkey_test_true(5);
    mMonkeys.back()->add_monkey_test_false(2);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 1
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(82);
    mMonkeys.back()->add_operation(Operation::ADD, 7);
    mMonkeys.back()->add_test(13);
    mMonkeys.back()->add_monkey_test_true(4);
    mMonkeys.back()->add_monkey_test_false(3);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 2
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(84);
    mMonkeys.back()->add_item(93);
    mMonkeys.back()->add_item(70);
    mMonkeys.back()->add_operation(Operation::ADD, 2);
    mMonkeys.back()->add_test(5);
    mMonkeys.back()->add_monkey_test_true(5);
    mMonkeys.back()->add_monkey_test_false(1);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 3
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(78);
    mMonkeys.back()->add_item(56);
    mMonkeys.back()->add_item(85);
    mMonkeys.back()->add_item(93);
    mMonkeys.back()->add_operation(Operation::MULT, 2);
    mMonkeys.back()->add_test(3);
    mMonkeys.back()->add_monkey_test_true(6);
    mMonkeys.back()->add_monkey_test_false(7);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 4
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(64);
    mMonkeys.back()->add_item(57);
    mMonkeys.back()->add_item(81);
    mMonkeys.back()->add_item(95);
    mMonkeys.back()->add_item(52);
    mMonkeys.back()->add_item(71);
    mMonkeys.back()->add_item(58);
    mMonkeys.back()->add_operation(Operation::POW, 0);
    mMonkeys.back()->add_test(11);
    mMonkeys.back()->add_monkey_test_true(7);
    mMonkeys.back()->add_monkey_test_false(3);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 5
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(58);
    mMonkeys.back()->add_item(71);
    mMonkeys.back()->add_item(96);
    mMonkeys.back()->add_item(58);
    mMonkeys.back()->add_item(68);
    mMonkeys.back()->add_item(90);
    mMonkeys.back()->add_operation(Operation::ADD, 6);
    mMonkeys.back()->add_test(17);
    mMonkeys.back()->add_monkey_test_true(4);
    mMonkeys.back()->add_monkey_test_false(1);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 6
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(56);
    mMonkeys.back()->add_item(99);
    mMonkeys.back()->add_item(89);
    mMonkeys.back()->add_item(97);
    mMonkeys.back()->add_item(81);
    mMonkeys.back()->add_operation(Operation::ADD, 1);
    mMonkeys.back()->add_test(7);
    mMonkeys.back()->add_monkey_test_true(0);
    mMonkeys.back()->add_monkey_test_false(2);
    mMonkeys.back()->add_factor_worry(9699690);

    // Monkey 7
    mMonkeys.push_back(std::make_unique<Monkey>());
    mMonkeys.back()->add_item(68);
    mMonkeys.back()->add_item(72);
    mMonkeys.back()->add_operation(Operation::ADD, 8);
    mMonkeys.back()->add_test(19);
    mMonkeys.back()->add_monkey_test_true(6);
    mMonkeys.back()->add_monkey_test_false(0);
    mMonkeys.back()->add_factor_worry(9699690);
}
