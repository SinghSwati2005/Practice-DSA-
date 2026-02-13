#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int longest_subarray_sum(vector<int>&nums){
   
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == 0) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}



int main(){
    int n  ;
    cin>>n;

    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    cout<<longest_subarray_sum(nums)<<" ";
    return 0;
}