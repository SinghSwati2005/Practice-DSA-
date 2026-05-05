#include<bits/stdc++.h>
using namespace std;

vector<int> assign_rank(vector<int>&nums){
    int n = nums.size();
vector<int>res(n);
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

for(int i =0;i<nums.size();i++){
    pq.push({nums[i],i});
}
int rank =1;
int prevval = INT_MIN;
while(!pq.empty()){
    auto p = pq.top();
    int val = p.first;
    int idx = p.second;
    pq.pop();

    if(val!=prevval){
        prevval = val;
    }
    res[idx]=rank;
    rank++;
}
return res;

}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>res = assign_rank(nums);
    for(int num : res){
        cout<<num<<" ";

    }
    return 0;
}
