#include "Day07.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <stack>
#include <string>
#include <type_traits>
#include "../utils/format.h"
#include "../utils/string.h"

constexpr int small_folder_size = 100000;
constexpr int total_space = 70000000;
constexpr int update_needed_space = 30000000;

Entry::Entry(const std::string &name, bool isFolder, int size) :
    mName(std::move(name)), mSize{size}, mIsFolder(isFolder)
{}

void Entry::add_subfolder(const std::string &name)
{
    auto folder = std::make_shared<Entry>(name, true);
    mChilds[folder->mName] = folder;
    folder->mParent = shared_from_this();
}

void Entry::add_file(const std::string &name, int size)
{
    auto file = std::make_shared<Entry>(name, false, size);
    mChilds[file->mName] = file;
    file->mParent = shared_from_this();

    // Update size to the root
    auto current = this;
    while (current) {
        current->mSize += file->mSize;
        current = current->mParent.get();
    }
}

Day07::Day07(std::string execFolder) :
    mInputFile{execFolder + "/input/Day07.txt"}, mRootFolder{std::make_shared<Entry>("/", true)}
{
    utils::format::print_title(7);
    ReadData();
}

int Day07::Puzzle1()
{
    int answer = 0;

    // dfs
    std::stack<std::shared_ptr<Entry>> stack;
    stack.push(mRootFolder);
    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();
        if (current->mIsFolder) {
            if (current->mSize <= small_folder_size) {
                answer += current->mSize;
            }
            for (auto child : current->mChilds) {
                if (child.second->mIsFolder) {
                    stack.push(child.second);
                }
            }
        }
    }

    utils::format::print_answer(1, answer);
    return answer;
}

int Day07::Puzzle2()
{
    int answer = 0;

    // dfs
    std::vector<std::shared_ptr<Entry>> folders;
    std::stack<std::shared_ptr<Entry>> stack;
    stack.push(mRootFolder);
    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();
        if (current->mIsFolder) {
            folders.push_back(current);
            for (auto child : current->mChilds) {
                if (child.second->mIsFolder) {
                    stack.push(child.second);
                }
            }
        }
    }

    int needed_space = update_needed_space - (total_space - mRootFolder->mSize);
    std::sort(folders.begin(), folders.end(), CmpEntry());
    for (auto folder : folders) {
        if (folder->mSize >= needed_space) {
            answer = folder->mSize;
            break;
        }
    }

    utils::format::print_answer(2, answer);
    return answer;
}

void Day07::ReadData()
{
    std::ifstream ifs(mInputFile, std::ios::binary);

    std::shared_ptr<Entry> currentFolder;
    for (std::string line; std::getline(ifs, line);) {
        auto split = utils::string::split(line, ' ');
        if (split[0] == "$") {
            if (split[1] == "cd") {
                if (split[2] == "/") {
                    currentFolder = mRootFolder;
                }
                else if (split[2] == "..") {
                    currentFolder = currentFolder->mParent;
                }
                else {
                    currentFolder = currentFolder->mChilds[split[2]];
                }
            }
        }
        else {
            if (split[0] == "dir") {
                currentFolder->add_subfolder(split[1]);
            }
            else {
                currentFolder->add_file(split[1], std::stoi(split[0]));
            }
        }
    }
}
