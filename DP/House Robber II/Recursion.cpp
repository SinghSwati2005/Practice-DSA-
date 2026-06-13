#include<iostream>
#include <vector>
#include <climits>
using namespace std;


int helper(int i , vector<int>&nums){
    if(i ==0) return nums[0];
    if(i<0) return 0;

    int pick = nums[i] + helper(i-2, nums);
    int notpick = 0 + helper(i-1, nums);
    return max(pick , notpick);
}



int robStreet(vector<int>&nums){
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];;
vector<int>nums1(nums.begin()+1,nums.end() );

int ans1 = helper(nums1.size()-1, nums1);

vector<int>nums2(nums.begin(), nums.end()-1);
int ans2 = helper(nums2.size()-1 , nums2);

  return   max(ans1, ans2);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << robStreet(nums) << endl;
    return 0;
}