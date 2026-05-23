# Dynamic Programming

## Overview
Dynamic programming solves problems by breaking them into overlapping subproblems and storing results to avoid recomputation. The two approaches are top-down (memoization) and bottom-up (tabulation).

## Core Concepts
- **Optimal substructure**: Optimal solution contains optimal solutions to subproblems
- **Overlapping subproblems**: Same subproblems solved multiple times — memoize them
- **State definition**: Identify what variables uniquely define a subproblem
- **Transition**: How to compute `dp[i]` from previous states
- **Base case**: Initial values that don't depend on other subproblems

## Algorithms

### Fibonacci / Climbing Stairs
Linear DP with two rolling variables. State: `dp[i]` = ways to reach step i.

### 0/1 Knapsack
State: `dp[w]` = max value with weight capacity w. Iterate items outer, capacity inner (reverse to prevent reuse).

### Coin Change
State: `dp[i]` = min coins to make amount i. Unbounded — iterate coins inner, allow reuse.

### LIS (Longest Increasing Subsequence)
O(n²) DP or O(n log n) patience sorting with binary search on `tails` array.

### LCS (Longest Common Subsequence)
2D DP. If characters match: `dp[i][j] = dp[i-1][j-1] + 1`. Else: `max(dp[i-1][j], dp[i][j-1])`.

### Edit Distance
2D DP. Base cases: empty string costs. Transitions: replace, insert, delete.

### Interval DP
State over ranges `[i, j]`. Loop by increasing length. Try all split points k.

## Complexity Table

| Problem              | Time      | Space    | Type        |
|----------------------|-----------|----------|-------------|
| Fibonacci            | O(n)      | O(1)     | Linear      |
| 0/1 Knapsack         | O(n·W)    | O(W)     | 2D → 1D     |
| Coin Change          | O(n·A)    | O(A)     | Unbounded   |
| LIS (DP)             | O(n²)     | O(n)     | Linear      |
| LIS (Binary Search)  | O(n log n)| O(n)     | Linear      |
| LCS                  | O(m·n)    | O(m·n)   | 2D          |
| Edit Distance        | O(m·n)    | O(m·n)   | 2D          |
| Interval DP          | O(n³)     | O(n²)    | Interval    |

## Patterns
- **1D DP**: Current state depends on previous 1-2 states (Fibonacci, climbing stairs)
- **2D DP**: State defined by two indices, often two sequences (LCS, edit distance)
- **Knapsack pattern**: Include/exclude decision for each item
- **Interval DP**: Solve smaller intervals first, combine for larger (matrix chain, burst balloons)
- **Bitmask DP**: State includes a subset bitmask (TSP, assignment problems)
- **DP on trees**: Post-order DFS; state per subtree

## Edge Cases
- Empty input — base case must handle 0 or empty; initialize dp[0] correctly
- Amount = 0 for coin change — return 0 (base case, not -1)
- Knapsack with weight 0 items — infinite loop risk; guard against it
- LCS of empty strings — `dp[0][*]` and `dp[*][0]` = 0
- Integer overflow — when summing large values, use `long long`

## Interview Usage
- **"House robber"** — linear DP, skip adjacent
- **"Word break"** — DP with dictionary lookup
- **"Unique paths"** — 2D grid DP
- **"Longest palindromic subsequence"** — LCS of string with its reverse
- **"Partition equal subset sum"** — 0/1 knapsack to target sum/2
- **"Decode ways"** — linear DP on string
- **"Burst balloons"** — interval DP (reverse thinking: last balloon to burst)
- **"Regular expression matching"** — 2D DP with `*` handling previous char