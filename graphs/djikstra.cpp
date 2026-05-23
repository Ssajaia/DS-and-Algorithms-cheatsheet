#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<int> dijkstra(const vector<vector<pii>>& adj, int src, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;
        if (d > dist[u]) continue;
        for (const pii& edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    };
    addEdge(0, 1, 4); addEdge(0, 2, 1); addEdge(2, 1, 2);
    addEdge(1, 3, 1); addEdge(2, 3, 5); addEdge(3, 4, 3);
    vector<int> dist = dijkstra(adj, 0, n);
    for (int i = 0; i < n; i++) cout << "dist[" << i << "] = " << dist[i] << "\n";
    return 0;
}