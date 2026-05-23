# Greedy

## Overview
Greedy algorithms make the locally optimal choice at each step with the hope of finding a global optimum. They work when a problem has the greedy-choice property and optimal substructure. Unlike DP, greedy does not reconsider past decisions.

## Core Concepts
- **Greedy-choice property**: A global optimum can be reached by making locally optimal choices
- **Optimal substructure**: Optimal solution contains optimal solutions to subproblems
- **Exchange argument**: Proof technique — show swapping any non-greedy choice with the greedy choice doesn't worsen the solution
- **Sorting as preprocessing**: Most greedy problems require sorting by some criterion first

## Algorithms

### Activity Selection
Sort by end time, greedily pick each non-overlapping activity. Proves optimal by exchange argument.

### Minimum Meeting Rooms
Sort starts and ends separately. Scan starts; if a start overlaps with earliest end, need new room; else reuse.

### Merge Intervals
Sort by start time. Extend current interval if overlap, else push new one.

### Jump Game II (Minimum Jumps)
Track the farthest reachable index and the current jump boundary. Each time boundary is reached, make a jump.

### Huffman Coding
Build a prefix-free binary code using a min-heap. Merge two lowest-frequency nodes repeatedly. Produces optimal variable-length encoding.

## Complexity Table

| Algorithm            | Time       | Space  | Notes                        |
|----------------------|------------|--------|------------------------------|
| Activity Selection   | O(n log n) | O(1)   | Sort by end time             |
| Meeting Rooms        | O(n log n) | O(n)   | Sort starts/ends separately  |
| Merge Intervals      | O(n log n) | O(n)   | Sort by start                |
| Jump Game II         | O(n)       | O(1)   | Linear scan                  |
| Huffman Coding       | O(n log n) | O(n)   | Priority queue               |

## Patterns
- **Sort then scan**: Sort by end time (activity selection), start time (intervals), or custom key
- **Two-pointer on sorted arrays**: Assign tasks, match workers to jobs
- **Greedy on answer**: Can I achieve X? Binary search on X + greedy feasibility check
- **Regret-based greedy**: Add everything, then greedily remove worst (used in some scheduling)

## Edge Cases
- Empty input — return 0 or empty result immediately
- Single interval — trivially 1 activity, 1 room, no merging needed
- All intervals overlapping — meeting rooms = number of intervals; activity selection = 1
- Intervals with same start or end — ensure sort stability or handle ties explicitly
- Jump game: if a position is 0 and not final, early termination needed

## Interview Usage
- **"Non-overlapping intervals"** — sort by end time, count removals
- **"Minimum number of arrows"** — sort by end, extend current interval
- **"Task scheduler"** — greedily schedule most frequent first; count idle slots
- **"Gas station"** — greedy scan with running sum reset
- **"Candy"** — two-pass greedy (left-to-right, right-to-left)
- **"Partition labels"** — greedy window extended to last occurrence of each character
- **"Jump game"** — greedy max-reach scan; O(n)