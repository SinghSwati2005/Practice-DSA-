#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int fruit_in_basket(vector<int>&nums){
    int n = nums.size();
  
    int maxlen =0;
    for(int i =0;i<n;i++){
          unordered_map<int,int>mpp;
          int cnt =0;
       for(int j =i;j<n;j++){
         mpp[nums[j]]++;
       
       if(mpp.size()>2) break;
       cnt++;
       }
       maxlen = max(maxlen,cnt);
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