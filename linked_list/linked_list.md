# Linked List

## Overview
A linked list is a linear data structure where each node contains a value and a pointer to the next node. Unlike arrays, linked lists allow O(1) insertions and deletions at any known position without shifting elements.

## Core Concepts
- **Singly linked list**: Each node has one `next` pointer
- **Doubly linked list**: Each node has `prev` and `next` pointers; enables O(1) removal given a node pointer
- **Sentinel/dummy node**: A dummy head simplifies edge cases (empty list, head deletion)
- **Floyd's cycle detection**: Fast/slow pointers detect cycles in O(n) time and O(1) space
- **Two-pointer technique**: Fast pointer running ahead by k steps finds kth-from-end in one pass

## Algorithms

### Reverse Linked List
Iteratively rewires `next` pointers using three pointers: `prev`, `curr`, `next`. O(n) time, O(1) space.

### Merge Sorted Lists
Uses a dummy head and compares front nodes, advancing the smaller one. O(m+n) time.

### Remove Nth From End
Fast pointer advances n+1 steps ahead; when fast reaches null, slow points to the node before the target.

### Cycle Detection (Floyd's)
Slow pointer moves one step, fast moves two. If they meet, a cycle exists. To find cycle start, reset one pointer to head and advance both one step at a time.

### Find Middle
Slow moves one step, fast moves two. When fast reaches end, slow is at middle.

## Complexity Table

| Operation            | Singly LL | Doubly LL | Array  |
|----------------------|-----------|-----------|--------|
| Access by index      | O(n)      | O(n)      | O(1)   |
| Insert at head       | O(1)      | O(1)      | O(n)   |
| Insert at tail       | O(n)/O(1) | O(1)      | O(1)*  |
| Delete at head       | O(1)      | O(1)      | O(n)   |
| Delete given node    | O(n)      | O(1)      | O(n)   |
| Search               | O(n)      | O(n)      | O(n)   |

## Patterns
- Use a **dummy head node** to avoid special-casing head removal
- **Two pointers**: one fast, one slow — for middle, cycle, kth-from-end
- **Recursion** for reversal, but prefer iteration to avoid stack overflow
- **In-place reversal of sublists**: track four boundary pointers
- Linked lists underlie LRU Cache (doubly linked list + hash map)

## Edge Cases
- Empty list — always check `head == nullptr` before dereferencing
- Single node — reversal, merge, removal all need care
- Cycle in list — Floyd's handles it; standard traversal loops infinitely
- Removing head node — use dummy node to avoid null-pointer issues
- Memory leaks — delete nodes explicitly in C++

## Interview Usage
- **"Reverse linked list"** — iterative three-pointer technique
- **"LRU Cache"** — doubly linked list + unordered_map
- **"Merge k sorted lists"** — min-heap or divide-and-conquer with merge pairs
- **"Reorder list"** — find middle, reverse second half, merge
- **"Detect cycle + find start"** — Floyd's algorithm extended
- **"Palindrome linked list"** — find middle, reverse second half, compare