#include<bits/stdc++.h>
using namespace std;

bool hands_of_straights(vector<int>&nums , int k){
unordered_map<int, int>mpp;
for(int x : nums){
    mpp[x]++;
}
priority_queue<int, vector<int>,greater<int>>pq;
for(auto &it : mpp){
    pq.push(it.first);
}
while(!pq.empty()){
    int start = pq.top();
    for(int i =0;i<k;i++){
        int curr = start +i;//consecutive value
        if(mpp[curr]==0) return false;
        mpp[curr]--;
        if(mpp[curr]==0){
            if(curr!=pq.top()) return false;
            pq.pop();
        }
    }
}
return true;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<((hands_of_straights(nums,k))?"true":"false");

return 0;
}