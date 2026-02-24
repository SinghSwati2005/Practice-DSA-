/* Input : arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Input : arr = [3,4,5,1,2]
Output : 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times. */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int count_rotate(vector<int>&nums){
    int n = nums.size();
  
  int low =0;
  int high = n-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]>nums[high]){
        low = mid+1;
    }
    else{
        // to keep the mid element as n candidate for search space we write high = mid . doing mid-1 would skip the mid element which can also be as small ekement
        high = mid;
    }
  }
   
   return low;
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