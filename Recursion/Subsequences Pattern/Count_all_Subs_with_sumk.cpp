#include<iostream>
#include<vector>
using namespace std;

int helper(int index, int sum , vector<int>&nums){
    if(sum==0) return 1;
    if(sum <0 || index == nums.size()) return 0;


    int exclude = helper(index+1, sum , nums);
    int include = helper(index+1, sum- nums[index], nums);

    return exclude+include;
}

int count(vector<int>&nums, int k){
    return helper(0,k,nums);
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<count(nums,k)<<" ";
    return 0;
}