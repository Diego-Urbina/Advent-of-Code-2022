#pragma once
#include <string>
#include <unordered_map>
#include <vector>

enum class Day16Action
{
    Ready = 0,
    Moving,
    Opening,
    Waiting,
    Idle
};

struct PlayerState
{
    Day16Action action = Day16Action::Ready;
    int remaining_minutes_moving = 0;
    int current_valve = 0;
    int current_minute = 0;
    int total_production = 0;
    int production = 0;
};

class Day16
{
public:
    Day16(std::string path);
    int Puzzle1();
    int Puzzle2();

private:
    void ReadData();

    void find_shortest_paths();
    void puzzle1(PlayerState person);
    void puzzle2(PlayerState person, PlayerState elephant);
    // void puzzle1(int total_production, int production, int minute, PlayerState person);

    std::vector<PlayerState> create_new_states(PlayerState person);

    std::string mInputFile;
    std::unordered_map<std::string, int> mValveToId;
    std::vector<std::vector<int>> mGraph;
    std::vector<int> mFlowRate;
    std::vector<bool> mValveIsOpen;
    std::vector<std::vector<int>> mShortestPaths;
    int mNumValves;

    PlayerState person;
    PlayerState elephant;

    int mMaxProduction = 0;
    const int time_limit_part1 = 30;
    const int time_limit_part2 = 26;
};
