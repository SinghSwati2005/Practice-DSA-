#include<bits/stdc++.h>
using namespace std;

int helper(int i , vector<int>&nums){
    if(i==0) return 0;
    int left = helper(i-1, nums) + abs(nums[i]-nums[i-1]);
    int right = INT_MAX;
    if(i>1){

    
    right = helper(i-2,nums) + abs(nums[i] -nums[i-2]);
    }
    return min(left,right);

}

int frogJump(vector<int>&nums){
    int n = nums.size();
    return helper(n-1, nums);
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