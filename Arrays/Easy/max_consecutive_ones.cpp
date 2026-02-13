
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int max_consecutive_one(vector<int> &nums){
    int count =0 , maxcount=0;
   
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
             maxcount = max(maxcount,count);
        }
        else{
            count =0;
        }
    }
    return maxcount;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    max_consecutive_one(nums);
    cout<<max_consecutive_one(nums)<<"";
    return 0;

    
    
}