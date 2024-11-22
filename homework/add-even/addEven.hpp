#pragma once
#include <algorithm>
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int result = 0;
    std::for_each(numbers.begin(), numbers.end(), [&result](int el) {
        if (el % 2 == 0) {
            result += el;
        }
    });

    return result;
}
