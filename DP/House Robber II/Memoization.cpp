#include <bits/stdc++.h>
using namespace std;

int helper(int i, vector<int>& nums, vector<int>& dp) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;

    if (dp[i] != -1) return dp[i];

    int pick = nums[i] + helper(i - 2, nums, dp);
    int notpick = helper(i - 1, nums, dp);

    return dp[i] = max(pick, notpick);
}

int robStreet(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Case 1: exclude first house
    vector<int> nums1(nums.begin() + 1, nums.end());
    vector<int> dp1(nums1.size(), -1);
    int ans1 = helper(nums1.size() - 1, nums1, dp1);

    // Case 2: exclude last house
    vector<int> nums2(nums.begin(), nums.end() - 1);
    vector<int> dp2(nums2.size(), -1);
    int ans2 = helper(nums2.size() - 1, nums2, dp2);

    return max(ans1, ans2);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << robStreet(nums) << endl;
    return 0;
}
