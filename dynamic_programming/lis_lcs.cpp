#include <bits/stdc++.h>
using namespace std;

int lisDP(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
}

int lisBinarySearch(const vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

int lcs(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
}

int editDistance(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    return dp[m][n];
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lisDP(arr) << "\n";
    cout << lisBinarySearch(arr) << "\n";
    cout << lcs("abcde", "ace") << "\n";
    cout << editDistance("horse", "ros") << "\n";
    return 0;
}