#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int single_number(vector<int>&nums){
    int n = nums.size();
   unordered_map<int,int>mpp;

    for(int i = 0;i<n;i++){
       mpp[nums[i]]++;
}
      for(auto &it :  mpp){
           if(it.second ==1)
           return it.first;
      }   
    }
   

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
        for (int i =0;i<n;i++){
            cin>>nums[i];
        
    }
    
    cout<<single_number(nums)<<" ";
    return 0;
}