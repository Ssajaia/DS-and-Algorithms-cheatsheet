#include <bits/stdc++.h>
using namespace std;

vector<int> topoSortKahn(int n, const vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) inDegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--inDegree[v] == 0) q.push(v);
    }
    return order.size() == n ? order : vector<int>{};
}

void dfsTopoHelper(const vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfsTopoHelper(adj, v, visited, st);
    st.push(u);
}

vector<int> topoSortDFS(int n, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) if (!visited[i]) dfsTopoHelper(adj, i, visited, st);
    vector<int> order;
    while (!st.empty()) { order.push_back(st.top()); st.pop(); }
    return order;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5].push_back(2); adj[5].push_back(0);
    adj[4].push_back(0); adj[4].push_back(1);
    adj[2].push_back(3); adj[3].push_back(1);
    auto order = topoSortKahn(n, adj);
    for (int v : order) cout << v << " "; cout << "\n";
    auto order2 = topoSortDFS(n, adj);
    for (int v : order2) cout << v << " "; cout << "\n";
    return 0;
}