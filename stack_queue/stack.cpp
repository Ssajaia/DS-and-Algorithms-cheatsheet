#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st, minSt;
public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};

bool isValidParentheses(const string& s) {
    stack<char> st;
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int largestRectangleInHistogram(const vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    vector<int> h = heights;
    h.push_back(0);
    for (int i = 0; i < (int)h.size(); i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    MinStack ms;
    ms.push(5); ms.push(3); ms.push(7);
    cout << ms.getMin() << "\n";
    cout << isValidParentheses("{[()]}") << "\n";
    vector<int> hist = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleInHistogram(hist) << "\n";
    return 0;
}