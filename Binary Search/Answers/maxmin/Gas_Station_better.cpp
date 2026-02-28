#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <queue>

using namespace std;
long double GasStation(vector<int>&nums , int k){
    int n = nums.size();
    vector<int>howmany(n-1,0);
    priority_queue<pair<long double , int>>pq;

    for(int i=0;i<n-1;i++){
        long double length = nums[i+1]- nums[i];
        pq.push({length ,i});
    }
    for(int gasStations = 1;gasStations<=k;gasStations++){
        auto top = pq.top();
        pq.pop();
        int segmentIndex = top.second;
        howmany[segmentIndex]++;
        long double totalDist= nums[segmentIndex+1]- nums[segmentIndex];
        long double newlen = totalDist/(howmany[segmentIndex]+1);
        pq.push({newlen , segmentIndex});


    }
    return pq.top().first;
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    cout<<fixed<<setprecision(6);
    cout<<GasStation(nums,k)<<" ";
    return 0;
}