#include <bits/stdc++.h>
using namespace std;

int ternarySearch(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;
        if (target < arr[mid1]) right = mid1 - 1;
        else if (target > arr[mid2]) left = mid2 + 1;
        else { left = mid1 + 1; right = mid2 - 1; }
    }
    return -1;
}

double ternarySearchReal(double left, double right, auto f) {
    while (right - left > 1e-9) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;
        if (f(mid1) < f(mid2)) left = mid1;
        else right = mid2;
    }
    return (left + right) / 2.0;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    cout << ternarySearch(arr, 7) << "\n";
    auto f = [](double x) { return -(x - 3) * (x - 3) + 9; };
    cout << fixed << setprecision(6) << ternarySearchReal(0, 6, f) << "\n";
    return 0;
}