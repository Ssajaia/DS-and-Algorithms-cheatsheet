#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    vector<int> buf;
    int head, tail, sz, capacity;
public:
    CircularQueue(int k) : buf(k), head(0), tail(0), sz(0), capacity(k) {}
    bool enqueue(int val) {
        if (sz == capacity) return false;
        buf[tail] = val;
        tail = (tail + 1) % capacity;
        sz++;
        return true;
    }
    bool dequeue() {
        if (sz == 0) return false;
        head = (head + 1) % capacity;
        sz--;
        return true;
    }
    int front() { return sz == 0 ? -1 : buf[head]; }
    int rear() { return sz == 0 ? -1 : buf[(tail - 1 + capacity) % capacity]; }
    bool isEmpty() { return sz == 0; }
    bool isFull() { return sz == capacity; }
};

vector<int> slidingWindowMax(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < (int)arr.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(arr[dq.front()]);
    }
    return result;
}

class QueueUsingStacks {
    stack<int> inbox, outbox;
    void transfer() {
        if (outbox.empty())
            while (!inbox.empty()) { outbox.push(inbox.top()); inbox.pop(); }
    }
public:
    void push(int val) { inbox.push(val); }
    void pop() { transfer(); outbox.pop(); }
    int peek() { transfer(); return outbox.top(); }
    bool empty() { return inbox.empty() && outbox.empty(); }
};

int main() {
    CircularQueue cq(3);
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3);
    cout << cq.front() << " " << cq.rear() << "\n";
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    for (int v : slidingWindowMax(arr, 3)) cout << v << " ";
    cout << "\n";
    return 0;
}