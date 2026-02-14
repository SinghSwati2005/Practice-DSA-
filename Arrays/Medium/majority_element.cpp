#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int majority_element(vector<int>&nums){
    int n = nums.size();
    int count =0;
    unordered_map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(auto &it : mpp){
        if(it.second>n/2)
        return it.first;
    }
    return -1;
    
}
int main(){
   int n ;
    cin>>n;
    vector<int>nums(n);
   
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
 int result = majority_element(nums);
     
      cout<<result<<" ";
    
    
    return 0;  
}