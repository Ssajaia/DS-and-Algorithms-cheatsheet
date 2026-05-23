# Trees

## Overview
A tree is a connected acyclic graph. Binary trees (at most 2 children per node) are the most common in interviews. BSTs impose ordering: left < root < right, enabling O(h) search where h is height.

## Core Concepts
- **Height/depth**: Height = longest path to leaf; depth of root = 0
- **Complete binary tree**: All levels full except possibly the last, filled left to right
- **BST property**: All nodes in left subtree < root < all nodes in right subtree
- **Balanced tree**: Height is O(log n); AVL and Red-Black trees self-balance
- **LCA**: Lowest Common Ancestor of two nodes — deepest node that is ancestor of both

## Algorithms

### Inorder Traversal (Iterative)
Uses an explicit stack. Traverses left subtree → root → right subtree. For a BST, yields sorted order.

### Preorder Traversal (Iterative)
Uses a stack. Pushes right child first so left is processed first. Root → left → right.

### Postorder Traversal (Iterative)
Reverse of a modified preorder (root → right → left), then reverse the result.

### Level Order (BFS)
Uses a queue. Process all nodes at each depth level before moving to next.

### BST Insert / Delete / Search
Insert and search recurse by comparing with root. Deletion handles three cases: no children, one child, two children (replace with inorder successor).

### LCA — Binary Tree
Recursive post-order search: if both halves return non-null, current node is LCA.

### LCA — BST
Iterative: if both nodes are left of root, go left; if both right, go right; else root is LCA.

### LCA — Binary Lifting
Preprocesses O(n log n) ancestor table. Answers LCA queries in O(log n) on arbitrary trees.

## Complexity Table

| Operation         | BST Avg  | BST Worst | Balanced BST |
|-------------------|----------|-----------|--------------|
| Search            | O(log n) | O(n)      | O(log n)     |
| Insert            | O(log n) | O(n)      | O(log n)     |
| Delete            | O(log n) | O(n)      | O(log n)     |
| Inorder traversal | O(n)     | O(n)      | O(n)         |
| Height            | O(n)     | O(n)      | O(log n)     |

## Patterns
- **Top-down**: Pass info from root to leaves (e.g., isValidBST with min/max bounds)
- **Bottom-up**: Return info from leaves to root (e.g., height, LCA, balanced check)
- **Global variable**: Track state across recursive calls (diameter, max path sum)
- **Level order for width/zigzag**: Process by depth using queue size trick
- **Morris traversal**: O(1) space inorder by temporarily modifying tree structure

## Edge Cases
- Empty tree — always check `root == nullptr`
- Single node — often a valid base case; don't assume left/right exist
- Skewed tree (all left or all right) — worst-case O(n) BST height
- LCA when one node is ancestor of another — the ancestor itself is the LCA
- Integer overflow in validity check — use `long long` with LLONG_MIN/LLONG_MAX bounds

## Interview Usage
- **"Maximum depth / diameter of binary tree"** — recursive height computation
- **"Validate BST"** — top-down with min/max bounds
- **"Path sum"** — DFS tracking remaining sum
- **"Serialize and deserialize binary tree"** — preorder with null markers
- **"Construct BST from preorder traversal"** — monotonic stack or recursive with bounds
- **"Kth smallest in BST"** — inorder traversal counting
- **"Binary tree right side view"** — level order, take last element per level