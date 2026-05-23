#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) { long long c = a + b; a = b; b = c; }
    return b;
}

int knapsack01(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = capacity; w >= weights[i]; w--)
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    return dp[capacity];
}

int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
}

int climbingStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) { int c = a + b; a = b; b = c; }
    return b;
}

int main() {
    cout << fibonacci(10) << "\n";
    vector<int> w = {1, 3, 4, 5}, v = {1, 4, 5, 7};
    cout << knapsack01(w, v, 7) << "\n";
    cout << coinChange({1, 5, 11}, 15) << "\n";
    cout << climbingStairs(5) << "\n";
    return 0;
}