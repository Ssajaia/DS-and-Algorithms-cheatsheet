# Arrays

## Overview
Arrays are the most fundamental data structure. Most array problems are solved by recognizing a pattern — prefix sums, two pointers, or sliding window — that reduces an O(n²) brute force to O(n).

## Core Concepts
- **Prefix sum**: Precompute cumulative sums to answer range queries in O(1)
- **Two pointers**: Use left and right pointers moving toward each other or in the same direction
- **Sliding window**: Maintain a window over the array, expanding and shrinking based on a condition
- **Kadane's algorithm**: Maximum subarray sum in O(n) using a running max
- **Dutch National Flag**: Three-way partition using three pointers

## Algorithms

### Prefix Sum
Builds a cumulative sum array so that `sum(l, r) = prefix[r+1] - prefix[l]` in O(1). Extends to 2D grids with inclusion-exclusion.

### Two Pointers
Maintains two indices, often one at each end. Used for pair-sum problems, palindrome checks, removing duplicates, and container-with-most-water.

### Sliding Window
A variable-size or fixed-size window that slides across the array. The window shrinks when a constraint is violated. Used for longest substring, minimum subarray, and anagram detection.

### Minimum Window Substring
A classic sliding window with a frequency map. Expand right to include characters, shrink left when all required characters are matched.

## Complexity Table

| Technique        | Time    | Space  | Use Case                        |
|------------------|---------|--------|---------------------------------|
| Prefix Sum       | O(n)    | O(n)   | Range sum/count queries         |
| Two Pointers     | O(n)    | O(1)   | Sorted array pair problems      |
| Sliding Window   | O(n)    | O(k)   | Subarray/substring constraints  |
| Kadane's         | O(n)    | O(1)   | Maximum subarray sum            |
| 2D Prefix Sum    | O(m·n)  | O(m·n) | 2D range sum queries            |

## Patterns
- If the problem asks for a contiguous subarray with a sum/count constraint → sliding window
- If input is sorted and asks for a pair → two pointers
- If many range queries on a static array → prefix sum
- If ask for max/min subarray sum → Kadane's algorithm
- If need to partition around a value → Dutch National Flag (three pointers)

## Edge Cases
- Empty array — return 0 or handle explicitly
- All negative numbers — Kadane's must track `maxEndingHere` carefully
- Window size larger than array — return -1 or 0
- Integer overflow — use `long long` for prefix sums on large inputs
- Off-by-one in range queries: `prefix[r+1] - prefix[l]` vs `prefix[r] - prefix[l-1]`

## Interview Usage
- **"Maximum subarray"** — Kadane's algorithm
- **"Longest substring without repeating characters"** — sliding window with hash set
- **"Two sum"** (sorted) — two pointers; (unsorted) — hash map
- **"Container with most water"** — two pointers, greedy shrink shorter side
- **"Minimum window substring"** — sliding window with two frequency maps
- **"Subarray sum equals k"** — prefix sum with hash map storing counts
- **"Product of array except self"** — prefix and suffix product arrays