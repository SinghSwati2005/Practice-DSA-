#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longest_subarray_sum(vector<int>&nums, int k){
   
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}



int main(){
    int n ,k ;
    cin>>n;
    cin>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    cout<<longest_subarray_sum(nums,k)<<" ";
    return 0;
}