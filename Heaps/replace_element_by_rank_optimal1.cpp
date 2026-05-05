#include<bits/stdc++.h>
using namespace std;

vector<int> assign_rank(vector<int>&nums){
    int n = nums.size();
vector<int>sorted = nums;

sort(sorted.begin(),sorted.end());

unordered_map<int,int>mpp;
int rank =1;
for(int num : sorted){
    if(mpp.find(num)!=mpp.end()){
        mpp[num]= rank;
        rank++;
    }
}
vector<int>res;
for(int num : nums){
    res.push_back(mpp[num]);

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
