#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

vector<int> bellmanFord(int n, const vector<Edge>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (const Edge& e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }
    for (const Edge& e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            dist[e.v] = INT_MIN;
    }
    return dist;
}

vector<vector<int>> floydWarshall(int n, vector<vector<int>> dist) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

int main() {
    int n = 5;
    vector<Edge> edges = {{0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5},{3,4,3}};
    auto dist = bellmanFord(n, edges, 0);
    for (int i = 0; i < n; i++) cout << dist[i] << " "; cout << "\n";

    const int INF = INT_MAX;
    vector<vector<int>> grid = {
        {0,3,INF,7},{8,0,2,INF},{5,INF,0,1},{2,INF,INF,0}
    };
    auto result = floydWarshall(4, grid);
    for (auto& row : result) { for (int v : row) cout << (v == INF ? -1 : v) << " "; cout << "\n"; }
    return 0;
}