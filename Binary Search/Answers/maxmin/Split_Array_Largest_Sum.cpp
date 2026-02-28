#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countPartitions(vector<int>&nums, int maxsum){
 int n = nums.size();
    int partition = 1;
  int mp =0;
  for(int i =0;i<n;i++){
      if(mp+nums[i]<=maxsum){
        mp+= nums[i];
      }
      else{
        partition++;
        mp = nums[i];

      }
  }
  return partition;
}
int findLargestSum(vector<int>&nums,int n , int k){
  if(k>n) return -1;
  int low = *max_element(nums.begin(),nums.end());
  int high = accumulate(nums.begin(),nums.end(),0);
  while(low<=high){
    int mid = (low+high)/2;
    if(countPartitions(nums,mid) >k){
        low = mid+1;
    }
    else{
        high = mid-1;
    }

}
return low;
}
int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findLargestSum(nums, n, k)<<" ";
    return 0;
}