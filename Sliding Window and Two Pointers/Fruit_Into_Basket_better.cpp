#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int fruit_in_basket(vector<int>&nums){
    int n = nums.size();
  unordered_map<int,int>mpp;
    int maxlen =0;
    int l =0;
    for(int r=0;r<n;r++){
        mpp[nums[r]]++;
        if(mpp.size()>2) {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        maxlen = max(maxlen , r-l+1);

    }
    return maxlen;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<fruit_in_basket(nums)<<" ";
    return 0;
}