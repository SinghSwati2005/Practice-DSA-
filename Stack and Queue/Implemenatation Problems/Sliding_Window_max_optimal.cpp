#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

vector<int>sliding_window_max_optimal(vector<int>&nums, int k){
    int n = nums.size();
    deque<int>dq;

    vector<int>res;

    for(int i =0;i<nums.size();i++){
      // // Remove elements from the front if they are out of this window's range
      
      if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]< nums[i]){
            dq.pop_front();

        }
        dq.push_back(i);

        if(i>=k-1){
            res.push_back(nums[dq.front()]);
        }
    }

    return res;





}
int main(){
    int n ,k;
    cin>>n>>k;
    vector<int>nums(n,k);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans = sliding_window_max_optimal(nums,k);
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}