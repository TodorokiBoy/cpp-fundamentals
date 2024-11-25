#include "vectorFunctions.hpp"
#include <iostream>
#include <algorithm>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;
    for (int i = 0; i < count; i++) {
        result.push_back(std::make_shared<int>(i));
    }

    return result;
}

void add10(std::vector<std::shared_ptr<int>>& vec) {
    std::for_each(vec.begin(), vec.end(), [](auto el) {if (el != nullptr) *el += 10; });
}

void sub10(int* ptr) {
    if (ptr != nullptr) {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec) {
    std::for_each(vec.begin(), vec.end(), [](auto el) { sub10(el.get()); });
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    std::for_each(vec.begin(), vec.end(), [](auto el) { std::cout << *el << " "; });
    std::cout << "\n";
}