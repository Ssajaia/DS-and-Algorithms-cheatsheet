#include <bits/stdc++.h>
using namespace std;

int tspBitmaskDP(const vector<vector<int>>& dist) {
    int n = dist.size();
    int full = (1 << n) - 1;
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    dp[1][0] = 0;
    for (int mask = 1; mask <= full; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == INT_MAX / 2) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    int ans = INT_MAX;
    for (int u = 1; u < n; u++) ans = min(ans, dp[full][u] + dist[u][0]);
    return ans;
}

int assignmentProblem(const vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == INT_MAX) continue;
        int task = __builtin_popcount(mask);
        if (task == n) continue;
        for (int worker = 0; worker < n; worker++) {
            if (!(mask & (1 << worker))) {
                int newMask = mask | (1 << worker);
                dp[newMask] = min(dp[newMask], dp[mask] + cost[task][worker]);
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main() {
    vector<vector<int>> dist = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    cout << tspBitmaskDP(dist) << "\n";
    vector<vector<int>> cost = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    cout << assignmentProblem(cost) << "\n";
    return 0;
}