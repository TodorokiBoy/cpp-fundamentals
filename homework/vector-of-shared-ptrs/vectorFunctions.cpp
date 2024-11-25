#include "vectorFunctions.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;
    for (int i = 0; i < count; i++) {
        result.push_back(std::make_shared<int>(i));
    }

    return result;
}

void add10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto element : vec) {
        if (element != nullptr) {
            *element += 10;
        }
    }
}

void sub10(int* ptr) {
    if (ptr != nullptr) {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto element : vec) {
        if (element != nullptr) {
            sub10(element.get());
        }
    }
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (auto element : vec) {
        if (element != nullptr) {
            std::cout << element << " ";
        }
    }
    std::cout << "\n";
}