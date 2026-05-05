#include<bits/stdc++.h>
using namespace std;

int kth_smallest(vector<int>&nums , int k){
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>>pq;
  

    for(int i =0;i<n;i++){
        pq.push(nums[i]);

    }
    while(k-1){
        pq.pop();
        k--;
    }
    return pq.top();
}

int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<kth_smallest(nums,k);
    return 0;
}
