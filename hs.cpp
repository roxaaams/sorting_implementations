#include <algorithm>
#include <utility>

#include "hs.h"

HS::HS(const std::vector <int>& numbers) {
   for (const auto& num : numbers)
        HS::insert(num);
}

int HS::getParent(const int& node) {
    return (node - 1) / 2;
}

int HS::getLeftSon(const int& node) {
    return 2 * node + 1;
}

int HS::getRightSon(const int& node) {
    return 2 * node + 2;
}

void HS::heapifyUp(const int& node) {
    int parent = getParent(node);
    if (node && heap[parent] < heap[node]) {
        std::swap(heap[node], heap[parent]);
        heapifyUp(parent);
    }
}

void HS::heapifyDown(const int& node) {
    int left = getLeftSon(node);
    int right = getRightSon(node);

    int largest = node;

    if (left < size() && heap[left] > heap[node])
        largest = left;

    if (right < size() && heap[right] > heap[largest])
        largest = right;

    if (largest != node) {
        std::swap(heap[node], heap[largest]);
        heapifyDown(largest);
    }
}

void HS::insert(const int& value) {
    heap.push_back(value);
    heapifyUp(size() - 1);
}
