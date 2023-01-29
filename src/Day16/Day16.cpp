#include "Day16.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "../utils/dijkstra.h"
#include "../utils/format.h"
#include "../utils/string.h"

std::vector<PlayerState> Day16::create_new_states(PlayerState person)
{
    std::vector<PlayerState> new_person_states;

    if (person.action == Day16Action::Ready) {
        bool exist_valve = false;
        int current_valve = person.current_valve;
        for (int i = 0; i < mNumValves; i++) {
            if (mValveIsOpen[i]) {
                int from_current_to_i = mShortestPaths[current_valve][i];
                if (time_limit_part1 - person.current_minute > from_current_to_i) {
                    exist_valve = true;
                    person.action = Day16Action::Moving;
                    person.remaining_minutes_moving = from_current_to_i;
                    person.current_valve = i;
                    new_person_states.push_back(person);
                }
            }
        }

        if (!exist_valve) {
            person.action = Day16Action::Waiting;
            new_person_states.push_back(person);
        }
    }
    else if (person.action == Day16Action::Idle) {
        return {person};
    }
    else {
        person.total_production = person.total_production + person.production;
        person.current_minute++;

        if (person.action == Day16Action::Moving) {
            person.remaining_minutes_moving--;
            if (person.remaining_minutes_moving == 0) {
                person.action = Day16Action::Opening;
            }
        }
        else if (person.action == Day16Action::Opening) {
            person.action = Day16Action::Ready;
            person.production = person.production + mFlowRate[person.current_valve];
        }

        new_person_states.push_back(person);
    }

    return new_person_states;
}

void Day16::puzzle1(PlayerState person)
{
    if (person.current_minute == time_limit_part1) {
        person.action = Day16Action::Idle;
    }

    if (person.action == Day16Action::Idle) {
        if (person.total_production > mMaxProduction) {
            mMaxProduction = person.total_production;
        }
    }
    else {
        std::vector<PlayerState> person_new_states = create_new_states(person);

        for (auto &state : person_new_states) {
            if (state.action == Day16Action::Opening) {
                mValveIsOpen[state.current_valve] = false;
            }
            puzzle1(state);
            if (state.action == Day16Action::Opening) {
                mValveIsOpen[state.current_valve] = true;
            }
        }
    }
}

void Day16::puzzle2(PlayerState person, PlayerState elephant)
{
    if (person.current_minute == time_limit_part2) {
        person.action = Day16Action::Idle;
    }
    if (elephant.current_minute == time_limit_part2) {
        elephant.action = Day16Action::Idle;
    }

    if (person.action == Day16Action::Idle && elephant.action == Day16Action::Idle) {
        int total = person.total_production + elephant.total_production;
        if (total > mMaxProduction) {
            mMaxProduction = total;
        }
    }
    else {
        std::vector<PlayerState> person_new_states = create_new_states(person);
        std::vector<PlayerState> elephant_new_states = create_new_states(elephant);

        for (auto &person_state : person_new_states) {
            for (auto &elephant_state : elephant_new_states) {
                if (person_state.action == Day16Action::Opening) {
                    mValveIsOpen[person_state.current_valve] = false;
                }
                if (elephant_state.action == Day16Action::Opening) {
                    mValveIsOpen[elephant_state.current_valve] = false;
                }

                puzzle2(person_state, elephant_state);

                if (person_state.action == Day16Action::Opening) {
                    mValveIsOpen[person_state.current_valve] = true;
                }
                if (elephant_state.action == Day16Action::Opening) {
                    mValveIsOpen[elephant_state.current_valve] = true;
                }
            }
        }
    }
}

Day16::Day16(std::string execFolder) : mInputFile{execFolder + "/input/Day16.txt"}
{
    utils::format::print_title(16);
    ReadData();
}

int Day16::Puzzle1()
{
    mMaxProduction = 0;
    find_shortest_paths();
    person.current_valve = mValveToId["AA"];
    puzzle1(person);
    utils::format::print_answer(1, mMaxProduction);
    return mMaxProduction;
}

int Day16::Puzzle2()
{
    mMaxProduction = 0;
    find_shortest_paths();
    person.current_valve = mValveToId["AA"];
    elephant.current_valve = mValveToId["AA"];
    // puzzle2(person, elephant);
    utils::format::print_answer(2, mMaxProduction);
    return mMaxProduction;
}

void Day16::ReadData()
{
    std::unordered_map<std::string, std::vector<std::string>> conexions;
    std::ifstream ifs(mInputFile, std::ios::binary);
    for (std::string line; std::getline(ifs, line);) {
        auto split = utils::string::split(line, ' ');
        auto valveSource = split[1];
        auto rateString = utils::string::split(split[4], '=')[1];
        rateString.pop_back();
        auto rate = std::stoi(rateString);

        mValveToId[valveSource] = mValveToId.size();
        mFlowRate.push_back(rate);
        mValveIsOpen.push_back(rate != 0);

        for (int i = 9; i < split.size(); i++) {
            auto valveTarget = split[i];
            if (valveTarget.size() > 2) {
                valveTarget.pop_back();
            }
            conexions[valveSource].push_back(valveTarget);
        }
    }

    mNumValves = conexions.size();
    for (const auto &c : conexions) {
        auto key = c.first;
        auto val = c.second;

        while (mGraph.size() <= mValveToId[key]) {
            mGraph.push_back(std::vector<int>(mNumValves, 0));
        }
        for (const auto &v : val) {
            mGraph[mValveToId[key]][mValveToId[v]] = 1;
        }
    }
}

void Day16::find_shortest_paths()
{
    mShortestPaths.clear();
    for (int i = 0; i < mNumValves; i++) {
        mShortestPaths.push_back(utils::graphs::dijkstra(mGraph, i));
    }
}