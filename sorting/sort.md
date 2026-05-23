# Sorting

## Overview
Sorting algorithms reorder elements of a collection according to a comparison criterion. They are foundational to computer science and serve as building blocks for more complex algorithms.

## Core Concepts
- **In-place sorting**: Uses O(1) extra space (e.g., bubble, insertion, heap sort)
- **Stable sorting**: Preserves relative order of equal elements (e.g., merge sort, insertion sort)
- **Comparison-based sorting**: Lower bound of O(n log n) for comparison-based methods
- **Divide and conquer**: Used by merge sort and quick sort to achieve O(n log n) average
- **Adaptive sorting**: Performs better on partially sorted data (e.g., insertion sort)

## Algorithms

### Bubble Sort
Repeatedly swaps adjacent elements that are out of order. Includes an early-exit optimization when no swaps occur in a pass.

### Insertion Sort
Builds the sorted array one element at a time by inserting each new element into its correct position. Excellent for small or nearly sorted arrays.

### Merge Sort
Divides the array in half, recursively sorts both halves, then merges them. Guarantees O(n log n) and is stable. Requires O(n) extra space.

### Quick Sort
Selects a pivot, partitions elements around it, and recursively sorts sub-arrays. Fast in practice with O(n log n) average, but O(n²) worst case.

### Heap Sort
Builds a max-heap from the array, then repeatedly extracts the maximum. In-place and O(n log n) guaranteed, but not stable and has poor cache performance.

## Complexity Table

| Algorithm      | Best       | Average    | Worst      | Space  | Stable |
|----------------|------------|------------|------------|--------|--------|
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)   | Yes    |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)   | Yes    |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)   | Yes    |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n)| No   |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)   | No     |

## Patterns
- Use **merge sort** when stability matters or guaranteed O(n log n) is needed
- Use **quick sort** for in-place with average-case performance (randomize pivot to avoid worst case)
- Use **insertion sort** for small arrays (n < 20) or as the base case in hybrid sorts
- Use **heap sort** when both in-place and O(n log n) worst-case are required
- **Counting/Radix sort** beats O(n log n) when input range is limited

## Edge Cases
- Empty array or single-element array — all algorithms must handle gracefully
- Already sorted array — bubble and insertion sort degrade to O(n) with optimization
- Reverse-sorted array — worst case for naive quick sort pivot selection
- Array with all equal elements — stable sorts preserve order; verify partition logic handles duplicates
- Integer overflow when computing mid: use `left + (right - left) / 2` not `(left + right) / 2`

## Interview Usage
- **"Sort colors"** (Dutch National Flag) — three-way partition, quick sort variant
- **"Merge intervals"** — sort by start time first
- **"Find kth largest"** — partial quick sort (quickselect), O(n) average
- **"Count inversions"** — merge sort with inversion counting during merge step
- **"Meeting rooms"** — sort by start/end time
- Sorting is often a preprocessing step; always consider if input can be sorted to simplify the problem