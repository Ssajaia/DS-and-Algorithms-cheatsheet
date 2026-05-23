#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false);
    vector<int> order;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) { visited[v] = true; q.push(v); }
        }
    }
    return order;
}

vector<int> dfs(const vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false);
    vector<int> order;
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        order.push_back(u);
        for (int v : adj[u]) if (!visited[v]) st.push(v);
    }
    return order;
}

int countComponents(const vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            queue<int> q;
            q.push(i); visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) if (!visited[v]) { visited[v] = true; q.push(v); }
            }
        }
    }
    return count;
}

vector<int> shortestPathBFS(const vector<vector<int>>& adj, int src, int dst, int n) {
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;
    q.push(src); dist[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) { dist[v] = dist[u] + 1; parent[v] = u; q.push(v); }
        }
    }
    if (dist[dst] == -1) return {};
    vector<int> path;
    for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(0,2); addEdge(1,3); addEdge(2,4);
    for (int v : bfs(adj, 0, n)) cout << v << " "; cout << "\n";
    for (int v : dfs(adj, 0, n)) cout << v << " "; cout << "\n";
    return 0;
}