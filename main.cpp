#include <ctime>
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

#include "is.h"
#include "hs.h"

int n;
std::vector <int> numbers;

void read() {
    std::cout << "Please introduce the size of the set: \n"
              << "and then the elements: \n";
    try {
        std::cin >> n;
        numbers.resize(n);
        for (auto &num : numbers)
            std::cin >> num;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
}

void print(const std::vector <int>& sorted_numbers) {
    std::cout << "The sorted set: \n";
    for (const auto& sn: sorted_numbers)
        std::cout << sn << " ";
    std:: cout << "\n";
}

void insertionSort() {
    IS is(numbers);

    int index = numbers.size() - 1;
    std::vector <int> sorted_numbers(numbers.size());

    auto begin_time = clock();
    while (!is.empty()) {
        sorted_numbers[index--] = is.getMax();
    }
    std::cout << std::fixed << std::setprecision(2)
            << "Insertion sort took: "
            << 1000.0 * ( clock () - begin_time ) /  CLOCKS_PER_SEC
            << " ms\n";

    print(sorted_numbers);
}

void heapSort() {
    HS hs(numbers);

    int index = numbers.size() - 1;
    std::vector<int> sorted_numbers(numbers.size());

    auto begin_time = clock();
    while (!hs.empty()) {
        sorted_numbers[index--] = hs.getMax();
    }
    std::cout << std::fixed << std::setprecision(2)
            << "Heap sort took: "
            << 1000.0 * ( clock () - begin_time ) /  CLOCKS_PER_SEC
            << " ms\n";

    print(sorted_numbers);
}

void solve() {
    if (numbers.size() > 0) {
        insertionSort();
        heapSort();
    } else {
        std::cout << "\nThe set is empty. \n";
    }
}

int main() {
    read();
    solve();
    return 0;
}
