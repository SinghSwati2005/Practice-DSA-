#include <bits/stdc++.h>
using namespace std;

// Linear house robber using tabulation
long long solve(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<long long> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        long long pick = arr[i] + dp[i - 2];
        long long nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}

// Circular house robber
long long robStreet(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Case 1: exclude first house
    vector<int> arr1(nums.begin() + 1, nums.end());
    long long ans1 = solve(arr1);

    // Case 2: exclude last house
    vector<int> arr2(nums.begin(), nums.end() - 1);
    long long ans2 = solve(arr2);

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
