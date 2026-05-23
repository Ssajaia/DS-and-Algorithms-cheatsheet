# Searching

## Overview
Searching algorithms locate a target element within a data structure. The efficiency depends heavily on whether the data is sorted and the structure used to store it.

## Core Concepts
- **Linear search**: Scans every element; works on unsorted data
- **Binary search**: Halves the search space each step; requires sorted data
- **Ternary search**: Divides into thirds; useful for unimodal functions over continuous domains
- **Lower/Upper bound**: Variants of binary search returning first/last position of target
- **Predicate binary search**: Binary search on a monotone boolean function, not just values

## Algorithms

### Linear Search
Iterates through each element sequentially. O(n) time, O(1) space. Only option for unsorted or linked-list data.

### Binary Search
Repeatedly halves the search range by comparing the midpoint to the target. Requires a sorted array. Includes lower_bound and upper_bound variants for finding insertion points.

### Ternary Search
Divides the search space into three parts. Used primarily to find the maximum or minimum of a unimodal function over a continuous or discrete domain.

## Complexity Table

| Algorithm      | Best  | Average   | Worst     | Space | Requires Sorted |
|----------------|-------|-----------|-----------|-------|-----------------|
| Linear Search  | O(1)  | O(n)      | O(n)      | O(1)  | No              |
| Binary Search  | O(1)  | O(log n)  | O(log n)  | O(1)  | Yes             |
| Ternary Search | O(1)  | O(log₃ n) | O(log₃ n) | O(1)  | Yes (unimodal)  |

## Patterns
- **Binary search on answer**: When the answer is monotone (if X works, X+1 also works), binary search on the answer space
- **Rotated array search**: Modified binary search checks which half is sorted
- **Search in 2D matrix**: Treat as 1D with index mapping, or start from top-right corner
- **First/last occurrence**: Use lower_bound/upper_bound instead of standard binary search
- **Floating point binary search**: Use `while (right - left > 1e-9)` with enough iterations

## Edge Cases
- Empty array — return -1 immediately
- Single-element array — check if it matches target
- Target smaller than all elements or larger than all elements
- Duplicate elements — specify whether to return first, last, or any occurrence
- Overflow in midpoint calculation: use `left + (right - left) / 2`
- Off-by-one in lower/upper bound: `right = arr.size()` (not `size - 1`) for insertion-point semantics

## Interview Usage
- **"Search in rotated sorted array"** — binary search with extra condition to determine sorted half
- **"Find peak element"** — binary search comparing mid to neighbors
- **"Koko eating bananas"**, **"Capacity to ship packages"** — binary search on answer
- **"Median of two sorted arrays"** — binary search on partition point
- **"Find minimum in rotated sorted array"** — binary search variant
- Binary search appears whenever a problem has a monotone predicate over a sortable space
