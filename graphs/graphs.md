# Graphs

## Overview
A graph is a set of vertices connected by edges. Graphs model networks, dependencies, maps, and more. Key properties: directed/undirected, weighted/unweighted, cyclic/acyclic.

## Core Concepts
- **Adjacency list**: `vector<vector<int>>` — space efficient, O(V+E)
- **Adjacency matrix**: `int[V][V]` — O(1) edge lookup, O(V²) space
- **Connected component**: Maximal set of mutually reachable vertices
- **DAG**: Directed Acyclic Graph — enables topological sort
- **Negative cycle**: A cycle with total negative weight — Bellman-Ford detects it

## Algorithms

### BFS
Queue-based level-by-level traversal. Finds shortest path in unweighted graphs. O(V+E).

### DFS
Stack-based (or recursive) deep traversal. Detects cycles, finds SCCs, topological sort. O(V+E).

### Dijkstra
Min-heap based greedy shortest path for non-negative weights. O((V+E) log V).

### Bellman-Ford
Relaxes all edges V-1 times. Handles negative weights, detects negative cycles. O(VE).

### Floyd-Warshall
DP over all-pairs shortest paths. O(V³) time, O(V²) space. Simple triple nested loop.

### Topological Sort (Kahn's BFS)
Process nodes with in-degree 0. If output size < V, graph has a cycle.

### Topological Sort (DFS)
Push to stack after fully exploring a node's descendants. Reverse stack gives topological order.

### Union-Find (DSU)
Tracks connected components with path compression and union by rank. Near-O(1) per operation.

## Complexity Table

| Algorithm       | Time            | Space   | Notes                        |
|-----------------|-----------------|---------|------------------------------|
| BFS / DFS       | O(V + E)        | O(V)    | Visited array required       |
| Dijkstra        | O((V+E) log V)  | O(V)    | Non-negative weights only    |
| Bellman-Ford    | O(V · E)        | O(V)    | Handles negative weights     |
| Floyd-Warshall  | O(V³)           | O(V²)   | All-pairs shortest paths     |
| Topological Sort| O(V + E)        | O(V)    | DAGs only                    |
| DSU (amortized) | O(α(n)) ≈ O(1)  | O(V)    | Path compression + rank      |

## Patterns
- **Multi-source BFS**: Add all sources to queue before starting — finds min distance to any source
- **0-1 BFS**: Use deque; push front for 0-weight edges, back for 1-weight
- **Bipartite check**: 2-color during BFS/DFS; if conflict, not bipartite
- **Cycle detection (directed)**: DFS with 3-color (white/gray/black) or Kahn's zero-indegree check
- **DSU for Kruskal's MST**: Sort edges by weight, unite components greedily

## Edge Cases
- Disconnected graph — always iterate over all nodes, not just from node 0
- Self-loops — guard against `u == v` in cycle detection
- Negative weights — Dijkstra fails; use Bellman-Ford
- Overflow in Dijkstra — initialize distances to INT_MAX; check before adding
- Topological sort on cyclic graph — Kahn's returns empty (or partial) order

## Interview Usage
- **"Number of islands"** — BFS/DFS on grid or DSU
- **"Clone graph"** — BFS with hash map for visited nodes
- **"Course schedule"** — cycle detection via topological sort
- **"Network delay time"** — Dijkstra from source
- **"Cheapest flights within k stops"** — modified Bellman-Ford or BFS with level limit
- **"Redundant connection"** — DSU, detect cycle by checking if nodes already connected
- **"Alien dictionary"** — topological sort on character ordering graph