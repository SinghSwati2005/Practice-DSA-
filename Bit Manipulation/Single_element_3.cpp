#include<iostream>
#include<vector>
using namespace std;

vector<int>single3(vector<int>&nums){
    int n = nums.size();
    int xorr =0;
    for(int i=0;i<n;i++){
        xorr = xorr+nums[i];
    }
    int right = (xorr & (xorr-1))^xorr;
    int xorr1 =0;
    int xorr2= 0;
    for(int i =0;i<n;i++){
        if(nums[i]&right){
            xorr1 = xorr1 ^ nums[i];
        }
        else{
            xorr2 = xorr2 ^ nums[i];
        }
    }
    if(xorr1<xorr2) return {xorr1, xorr2};
 return {xorr2, xorr1};
    
}

int  main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }

    vector<int>res = single3(nums);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}