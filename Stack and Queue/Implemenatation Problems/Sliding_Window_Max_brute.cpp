#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;


vector<int>slidin_window_max(vector<int>&nums , int k){
    int n = nums.size();
    vector<int> result;
    for(int i =0;i<=n-k;i++){
        int maxval = nums[i];
        for(int j =i;j<i+k;j++){
            maxval = max(maxval,nums[j]);
        }
        result.push_back(maxval);
    }
    return result;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    vector<int>res = slidin_window_max(nums,k);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}


