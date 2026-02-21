/* Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

Examples
Input: Nums = [1,2,3,4,5,0]
Output: 120
Explanation: 
In the given array, 1×2×3×4×5 gives maximum product value.
Input: Nums = [1,2,-3,0,-4,-5]
Output: 20
Explanation: 
In the given array, (-4)×(-5) gives maximum product value. */


#include<iostream>
#include<vector>
using namespace std;
int max_product(vector<int>&nums){
    int n = nums.size();
   int res = nums[0];
   int maxP = nums[0];
   int minP = nums[0];
    for(int i=0;i<n;i++){
        int curr = nums[i];
        if(curr<0) swap(maxP,minP);

        maxP = max(curr, maxP*curr);
        minP = min(curr, minP*curr);

        res = max(res,maxP);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<max_product(nums)<<" ";
    return 0;
}
