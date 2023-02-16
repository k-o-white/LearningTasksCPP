//
// Created by teena on 15.02.2023.
//
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <filesystem>
#include "tasks.h"

void task1()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (auto &num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;
}

void task2()
{
    auto getUniqueValues = [](std::vector<int> &nums)
    {
        std::unordered_set<int> uSet;
        std::vector<int> newVec;

        for (auto num : nums)
            uSet.insert(num);

        for (auto num : uSet)
            newVec.emplace_back(num);

        std::sort(newVec.begin(), newVec.end());

        return std::make_unique<std::vector<int>>(newVec);
    };

    std::vector<int> numbers = {1, 3, 2, 5, 4, 3, 2, 2, 1, 6, 1, 1};
    auto vecPtr = getUniqueValues(numbers);

    for (auto num : *vecPtr)
        std::cout << num << " ";
    std::cout << std::endl;
}

void task3()
{
    auto recursiveGetFileNamesByExtension =
            [](const std::filesystem::path &path, const std::string &extension)
    {
        if (std::filesystem::is_regular_file(path) && !path.extension().compare(extension))
            std::cout << path << std::endl;
    };

    std::filesystem::path path;
    std::string extension;
    std::cout << "Input path: ";
    std::cin >> path;
    std::cout << "Input extension: ";
    std::cin >> extension;
    if (extension[0] != '.')
        extension = "." + extension;

    for (const auto& file : std::filesystem::recursive_directory_iterator(path))
        recursiveGetFileNamesByExtension(file.path(), extension);
}
