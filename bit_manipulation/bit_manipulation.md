# Bit Manipulation

## Overview
Bit manipulation operates directly on binary representations of integers. It enables O(1) tricks for tasks that would otherwise require loops, and underpins bitmask DP for subset enumeration.

## Core Concepts
- **AND (`&`)**: Both bits must be 1 — used to mask/check bits
- **OR (`|`)**: At least one bit is 1 — used to set bits
- **XOR (`^`)**: Bits differ — used to toggle, cancel pairs, detect differences
- **NOT (`~`)**: Flip all bits
- **Left shift (`<<`)**: Multiply by 2ⁿ
- **Right shift (`>>`)**: Divide by 2ⁿ (logical for unsigned, arithmetic for signed)

## Algorithms

### Bit Operations Reference
| Operation       | Expression       |
|-----------------|------------------|
| Get bit i       | `(n >> i) & 1`   |
| Set bit i       | `n \| (1 << i)`  |
| Clear bit i     | `n & ~(1 << i)`  |
| Toggle bit i    | `n ^ (1 << i)`   |
| Clear LSB       | `n & (n - 1)`    |
| Isolate LSB     | `n & (-n)`       |
| Power of two?   | `n > 0 && (n & (n-1)) == 0` |
| Count set bits  | `__builtin_popcount(n)` |

### XOR Tricks
- XOR of a number with itself is 0: `a ^ a = 0`
- XOR with 0 is identity: `a ^ 0 = a`
- XOR is commutative and associative
- **Single number**: XOR all elements — pairs cancel, lone element remains
- **Missing number**: XOR indices 0..n with array values

### Bitmask DP
State space is all 2ⁿ subsets of n elements. Each subset is an integer mask. Enables TSP, assignment problems, and optimal subset selection in O(2ⁿ · n).

## Complexity Table

| Operation             | Time   | Space |
|-----------------------|--------|-------|
| Any single bit op     | O(1)   | O(1)  |
| Count set bits        | O(1)   | O(1)  |
| Subset enumeration    | O(2ⁿ)  | O(2ⁿ) |
| Bitmask DP            | O(2ⁿ·n)| O(2ⁿ·n)|

## Patterns
- **Subset sum / knapsack with bitmask**: Enumerate all 2ⁿ subsets
- **Superset iteration**: `for (int sup = mask; sup < (1<<n); sup = (sup+1) | mask)`
- **Subset iteration**: `for (int sub = mask; sub > 0; sub = (sub-1) & mask)`
- **Odd/even check**: `n & 1` — 1 if odd, 0 if even
- **Swap without temp**: `a ^= b; b ^= a; a ^= b;`

## Edge Cases
- Shifting by ≥ bit width is undefined behavior in C++ — guard for `i < 32`
- Signed overflow: prefer `unsigned` or `long long` for bitmask operations
- Negative numbers: `n & (-n)` works due to two's complement representation
- `__builtin_popcount` operates on `int`; use `__builtin_popcountll` for `long long`
- Empty subset (mask = 0) — must be handled as a valid state in bitmask DP

## Interview Usage
- **"Single number"** — XOR all elements
- **"Missing number"** — XOR indices with values
- **"Counting bits"** — `dp[i] = dp[i >> 1] + (i & 1)`
- **"Reverse bits"** — bit-by-bit loop or lookup table
- **"Power of two"** — `n > 0 && (n & (n-1)) == 0`
- **"Sum of all subset XOR totals"** — bitmask enumeration
- **"Traveling Salesman"** — bitmask DP over visited-node subsets