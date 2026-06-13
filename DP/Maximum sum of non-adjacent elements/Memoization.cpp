#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums, int i, vector<int>&dp){
   if(i<0) return 0;
   if(i==0) return nums[i];

   if(dp[i]!=-1) return dp[i];


   int pick = nums[i] + helper(nums , i-2, dp);
   int notpick = helper(nums , i-1, dp);
   return dp[i]= max(pick , notpick);

}


int maxadj (vector<int>&nums){
    vector<int>dp(nums.size(),-1);
   return  helper(nums, nums.size()-1 ,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }

    cout<<maxadj(nums)<<" ";
    return 0;
}