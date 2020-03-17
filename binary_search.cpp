#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>


int bin_search(const std::vector<int> &numbers, int number) {
    int l = 0, r = numbers.size();
    int m = -1;

    while (l <= r) {
        m = (l + r) / 2;
        if (numbers[m] == number) {
            return m;
        } else if (numbers[m] > number) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return m;
}


int main() {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto &number:numbers) {
        std::cin >> number;
    }
    assert(std::is_sorted(numbers.begin(), numbers.end()));
    size_t query_number;
    std::cin >> query_number;

    while (query_number--> 0) {
        int number;
        std::cin >> number;
        std::cout << bin_search(numbers, number) << ' ';
    }

    std::cout << std::endl;
    return 0;
}