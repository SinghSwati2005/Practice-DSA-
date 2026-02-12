#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void left_roate_by_kplaces(vector<int> &nums, int k){
    k= k% nums.size();
    
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];


    }
    int k;
    cin>>k;
    left_roate_by_kplaces(nums,k);
    for(int i =0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}