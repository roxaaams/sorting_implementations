#ifndef IS_H_
#define IS_H_

#include <limits>
#include <vector>

#include "sorter_base.h"

class IS {
  private:
    std::vector <int> numbers;

  public:
    IS(std::vector <int>& numbers);

    int size() {
        return numbers.size();
    }

    bool empty() const {
        return numbers.empty();
    }

    int getMax() {
        int n = (int) numbers.size();
        int index = 0;
        int maxim = std::numeric_limits<int>::min();

        for (int i = 0; i < n; ++i)
            if (numbers[i] > maxim) {
                index = i;
                maxim = numbers[i];
            }

        erase(index);

        return maxim;
    }

    void erase(const int& index) {
        numbers.erase(numbers.begin() + index);
    }

    void insert(const int& value) {
        numbers.push_back(value);
    }
};

#endif
