#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int atmost(vector<int>&nums, int goal){
    int l =0;
    int r=0;
int n = nums.size();
int odd=0;
int cnt=0;
while(r<n){
    if(nums[r]%2!=0){
        odd++;
    }
    while(odd>goal){
       if(nums[l]%2!=0) odd--;
        l++;
    }
   
        cnt += (r-l+1);
        r++;
    
}
return cnt;
}


int nice_subarray_cnt(vector<int>&nums , int goal){
    
    if(goal<0) return 0;
    return atmost(nums, goal)- atmost(nums,goal-1);

    
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
    cout<<nice_subarray_cnt(nums,goal)<<" ";
    return 0;
}