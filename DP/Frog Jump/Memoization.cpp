#include<bits/stdc++.h>
using namespace std;

int helper(int i , vector<int>&nums,vector<int>&dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];

     int right = INT_MAX;

    int left = helper(i-1, nums,dp) + abs(nums[i]-nums[i-1]);
   
    if(i>1){

    
    right = helper(i-2,nums,dp) + abs(nums[i] -nums[i-2]);
    }
    return dp[i] = min(left,right);

}

int frogJump(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n,-1);
    return helper(n-1, nums,dp);
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