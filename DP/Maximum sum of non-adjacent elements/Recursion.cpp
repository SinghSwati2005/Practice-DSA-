#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums, int i){
    if(i==0) return nums[i];
    if(i<0) return 0;
    int pick = nums[i]+ helper(nums, i-2);
 int notpick = helper(nums, i-1);

 return max(pick, notpick);
}


int maxadj (vector<int>&nums){
   return  helper(nums, nums.size()-1 );
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }

    cout<<maxadj(nums)<<" ";
    return 0;
}