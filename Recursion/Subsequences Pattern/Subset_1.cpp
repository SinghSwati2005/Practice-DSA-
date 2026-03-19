#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void helper(vector<int>&nums, int n, int index , int sum,vector<int>&curr){
    if(index==n){
        curr.push_back(sum);
        return;

    }

    helper(nums,n,index+1,sum,curr);
   
    helper(nums,n,index+1,sum+ nums[index],curr);
    
}

vector<int>subset(vector<int>&arr, int n){
    vector<int>curr;
    
    helper(arr,n,0,0,curr);
    sort(arr.begin(),arr.end());
    return curr;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>res = subset(nums,n);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

