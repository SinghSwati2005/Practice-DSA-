#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n, 0);

    dp[0] = 0; // base case

    for(int i = 1; i < n; i++) {
        int left = dp[i-1] + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) {
            right = dp[i-2] + abs(height[i] - height[i-2]);
        }
        dp[i] = min(left, right);
    }

    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << frogJump(height) << endl;
    return 0;
}
