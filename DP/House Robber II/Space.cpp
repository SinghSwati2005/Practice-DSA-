#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];

    int prev = nums[0];
   int prev2=0;

    for(int i =0;i<n;i++){
        int pick = nums[i]+ prev2;
        int notpick = prev;
        int curr = max(pick , notpick);
        prev2=prev;
        prev = curr;

    }
    return prev;
}

int robStreet(vector<int>&nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];


    vector<int>nums1(nums.begin()+1, nums.end());
    int ans1 = helper(nums1);


    vector<int>nums2(nums.begin(),nums.end()-1);
    int ans2= helper(nums2);
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