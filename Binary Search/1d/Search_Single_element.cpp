/* Input : arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Output: 4
Explanation: Only the number 4 appears once in the array.

Input: arr[] = {1,1,3,5,5}
Output : 3
Explanation: Only the number 3 appears once in the array. */

#include<iostream>

#include<vector>
#include<algorithm>
using namespace std;
int count_rotate(vector<int>&nums){
    int n = nums.size();
  
  if(n==1) return nums[0];
  if(nums[0]!=nums[1]) return nums[0];
  if(nums[n-1]!=nums[n-2]) return nums[n-1];

  int low = 1, high = n-2;
  while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]!=nums[mid+1]&& nums[mid] != nums[mid-1]){
        return nums[mid];

    }
    if((mid%2==1 && nums[mid]== nums[mid-1]) || 
(mid%2==0&&nums[mid]==nums[mid+1])){
    low = mid+1;
}
else{
    high = mid-1;
}
  }
  return -1;

} 
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<count_rotate(nums);
    return 0;
}