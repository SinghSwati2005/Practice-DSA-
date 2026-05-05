#include<bits/stdc++.h>
using namespace std;

int taskScheduler(vector<char>&nums , int n){
    int m = nums.size();
    
    unordered_map<char,int>mpp;
    for(int i =0;i<m;i++){
        mpp[nums[i]]++;
    }

    priority_queue<int>pq;
    for(auto & entry : mpp){
        pq.push(entry.second);
    }
    int time =0;
    while(!pq.empty()){
vector<int>res;

int cycle = n+1;
int i =0;

while(i<cycle && !pq.empty()){
    int val = pq.top();
    pq.pop();
    val--;
    if(val>0){
        res.push_back(val);
    }
    time++;
    i++;
}

for(int x : res){
    pq.push(x);
}

if(pq.empty()) break;
//for idle slots
time+=(cycle-i);
    }
    return time;
    }
int main(){
    int n,k;
    cin>>n>>k;
    vector<char>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    cout<<taskScheduler(nums,k)<<"";
    return 0;

}