#include <vector>

#include "sorter_base.h"

class HS {
    private:
        std::vector <int> heap;

        int getParent(const int& node);

        int getLeftSon(const int& node);

        int getRightSon(const int& node);

        void heapifyUp(const int& node);

        void heapifyDown(const int& node);

        void insert(const int& value);

    public:
        HS(const std::vector <int>& numbers);

        int size() {
            return heap.size();
        }

        bool empty() const {
            return heap.empty();
        }

        int getMax() {
            int maxim = heap[0];

            erase(0);

            return maxim;
        }

        void erase(int index) {
            heap[index] = heap.back();
            heap.pop_back();
            heapifyDown(index);
        }
};
