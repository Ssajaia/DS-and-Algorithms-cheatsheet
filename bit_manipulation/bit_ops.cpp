#include <bits/stdc++.h>
using namespace std;

bool getBit(int n, int i) { return (n >> i) & 1; }
int setBit(int n, int i) { return n | (1 << i); }
int clearBit(int n, int i) { return n & ~(1 << i); }
int toggleBit(int n, int i) { return n ^ (1 << i); }
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
int countSetBits(int n) { return __builtin_popcount(n); }
int leastSignificantBit(int n) { return n & (-n); }
int clearLSB(int n) { return n & (n - 1); }

int singleNumber(const vector<int>& nums) {
    int result = 0;
    for (int n : nums) result ^= n;
    return result;
}

vector<int> singleNumberIII(const vector<int>& nums) {
    int xorAll = 0;
    for (int n : nums) xorAll ^= n;
    int diffBit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int n : nums) {
        if (n & diffBit) a ^= n;
        else b ^= n;
    }
    return {a, b};
}

int missingNumber(const vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < (int)nums.size(); i++) result ^= i ^ nums[i];
    return result;
}

void subsetEnumeration(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) if (mask & (1 << i)) subset.push_back(i);
    }
}

int reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {
    cout << isPowerOfTwo(16) << "\n";
    cout << countSetBits(15) << "\n";
    vector<int> nums = {2, 3, 1, 2, 3};
    cout << singleNumber(nums) << "\n";
    cout << missingNumber({0, 1, 3}) << "\n";
    return 0;
}