#include <bits/stdc++.h>
using namespace std;

int helper(int ind, vector<int>& nums, int k, vector<int>& dp) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int jump = helper(ind - j, nums, k, dp) + abs(nums[ind] - nums[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
}

int frogjumpMemo(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(n - 1, nums, k, dp);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];

    cout << frogjumpMemo(height, k) << endl;
    return 0;
}
