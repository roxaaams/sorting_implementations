#include <limits>
#include <vector>

#include "solution.h"

using namespace std;

class solution {
    private:
        vector <int> numbers;

    solution(vector <int>& numbers) : numbers(numbers) {}

    public:
        int getSize() {
            return numbers.size();
        }

        int findMax() {
            int maxim = numeric_limits<int>::min();
            for (const auto & it : numbers)
                maxim = max(it, maxim);
        }
};
