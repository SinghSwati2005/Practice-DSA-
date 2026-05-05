#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int pivot, int left, int right) {
    int pivotVal = nums[pivot];
    swap(nums[left], nums[pivot]);
    int ind = left + 1;

    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < pivotVal) { // for kth smallest
            swap(nums[ind], nums[i]);
            ind++;
        }
    }
    swap(nums[left], nums[ind - 1]);
    return ind - 1;
}

int randomIndex(int left, int right) {
    int len = right - left + 1;
    return (rand() % len) + left;
}

int kth_smallest(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return -1;

    int left = 0, right = n - 1;
    while (left <= right) {
        int pivot = randomIndex(left, right);
        pivot = partition(nums, pivot, left, right);

        if (pivot == k - 1) return nums[pivot];
        else if (pivot > k - 1) {
            right = pivot - 1;
        } else {
            left = pivot + 1;
        }
    }
    return -1; // only if not found
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << kth_smallest(nums, k) << "\n";
    return 0;
}
