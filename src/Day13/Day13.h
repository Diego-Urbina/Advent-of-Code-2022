#pragma once
#include <algorithm>
#include <optional>
#include <string>
#include <utility>
#include <variant>
#include <vector>

struct Node
{
    std::variant<int, std::vector<Node>> value;

    bool operator<(const Node &other) const
    {
        if (std::holds_alternative<int>(value) && std::holds_alternative<int>(other.value)) {
            return value < other.value;
        }

        if (std::holds_alternative<std::vector<Node>>(value) &&
            std::holds_alternative<std::vector<Node>>(other.value)) {
            return value < other.value;
        }

        if (std::holds_alternative<int>(value)) {
            return std::vector<Node>{{value}} < std::get<std::vector<Node>>(other.value);
        }
        else {
            return std::get<std::vector<Node>>(value) < std::vector<Node>{{other.value}};
        }
    }

    bool operator==(const Node &other) const
    {
        if (std::holds_alternative<int>(value) && std::holds_alternative<int>(other.value)) {
            return value == other.value;
        }

        if (std::holds_alternative<std::vector<Node>>(value) &&
            std::holds_alternative<std::vector<Node>>(other.value)) {
            if (std::get<std::vector<Node>>(other.value).size() ==
                std::get<std::vector<Node>>(other.value).size()) {
                return value == other.value;
            }
        }

        return false;
    }
};

class Day13
{
public:
    Day13(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    std::string mInputFile;
    std::vector<std::vector<Node>> mLists;
};
