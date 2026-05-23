#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] > heap[i]) { swap(heap[parent], heap[i]); i = parent; }
            else break;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void push(int val) { heap.push_back(val); siftUp(heap.size() - 1); }
    void pop() { heap[0] = heap.back(); heap.pop_back(); if (!heap.empty()) siftDown(0); }
    int top() { return heap[0]; }
    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }
};

vector<int> kLargestElements(const vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : arr) {
        minHeap.push(x);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    vector<int> result;
    while (!minHeap.empty()) { result.push_back(minHeap.top()); minHeap.pop(); }
    return result;
}

double medianFinder(vector<int>& stream) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : stream) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) { maxHeap.push(minHeap.top()); minHeap.pop(); }
    }
    return maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
}

int main() {
    MinHeap mh;
    for (int v : {5, 3, 8, 1, 6}) mh.push(v);
    while (!mh.empty()) { cout << mh.top() << " "; mh.pop(); }
    cout << "\n";
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    for (int v : kLargestElements(arr, 3)) cout << v << " ";
    cout << "\n";
    vector<int> stream = {5, 3, 8, 1};
    cout << medianFinder(stream) << "\n";
    return 0;
}