#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int nice_subarray_cnt(vector<int>&nums , int goal){
    int n = nums.size();
    
    int cnt = 0;
   unordered_map<int,int>mpp;
   mpp[0]=1;
   
   for(int i =0;i<n;i++)
{
    int odd =0;
   if(nums[i]%2!=0){
    odd++;
    if(mpp.find(odd-cnt)!=mpp.end()){
       cnt+=mpp[odd-cnt];
    }
    mpp[odd]++;
   }
}
return cnt;
    
}

int main(){
    int n;
    cin>>n;
    int goal;
    cin>>goal;

    vector<int>nums(n);

    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<nice_subarray_cnt(nums,goal)<<" ";
    return 0;
}