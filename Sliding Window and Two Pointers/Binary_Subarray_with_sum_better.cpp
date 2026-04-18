#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int binary_subarray_sum(vector<int>&nums , int goal){
    int n = nums.size();
    
    int cnt = 0;
    int sum =0;
    unordered_map<int,int>mpp;
    mpp[0]=1;
    for(int i =0;i<n;i++){
        int sum =0;
        
                sum+=nums[i];
                if(mpp.find(sum-goal)!=mpp.end()){
                    cnt+=mpp[sum-goal];
                }
                mpp[sum]++;
             
           
        
    }
    return cnt;

    
}

int main(){
    int n;
    cin>>n;
    int goal;
    cin>>goal;

    vector<int>nums(n);

    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<binary_subarray_sum(nums,goal)<<" ";
    return 0;
}