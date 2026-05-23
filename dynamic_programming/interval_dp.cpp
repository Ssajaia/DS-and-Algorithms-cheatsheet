#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(const string& s, const string& t) {
    int i = 0;
    for (char c : t) if (i < (int)s.size() && c == s[i]) i++;
    return i == (int)s.size();
}

int longestPalindromicSubstring(const string& s) {
    int n = s.size(), maxLen = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int i = 0; i < n - 1; i++) if (s[i] == s[i+1]) { dp[i][i+1] = true; maxLen = 2; }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1]) { dp[i][j] = true; maxLen = len; }
        }
    }
    return maxLen;
}

int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + nums[i] * nums[k] * nums[j] + dp[k][j]);
        }
    }
    return dp[0][n-1];
}

int matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    cout << isSubsequence("ace", "abcde") << "\n";
    cout << longestPalindromicSubstring("babad") << "\n";
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << "\n";
    vector<int> dims = {30, 35, 15, 5, 10, 20, 25};
    cout << matrixChainMultiplication(dims) << "\n";
    return 0;
}