#pragma once
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct Item
{
    long long mWorryLevel;
};

enum class Operation
{
    ADD,
    MULT,
    POW
};

class Monkey
{
public:
    void add_item(Item item);

    void add_item(int worryLevel);
    void add_operation(Operation op, int argument);
    void add_test(int argument);
    void add_monkey_test_true(int monkey);
    void add_monkey_test_false(int monkey);
    void add_factor_worry(int factor_worry);

    std::pair<Item, int> inspect_item(bool reduce_worry);
    bool is_empty();

    int get_inspections() const;

private:
    void update_item(Item &item);

    std::queue<Item> mItems;

    // TODO-function
    Operation mOperation;
    int mOperationArgument;

    int mTestArgument;
    int mMonkeyTestTrue;
    int mMonkeyTestFalse;
    int mFactorWorry;

    int mInspections;
};

class Day11
{
public:
    Day11(std::string path);
    int Puzzle1(bool test = false);
    long long Puzzle2(bool test = false);

private:
    void ReadData();

    void CreateMonkeyTest();
    void CreateMonkeyReal();

    std::string mInputFile;
    std::vector<std::unique_ptr<Monkey>> mMonkeys;
};
