
/* Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Search_X_Sorted(vector<int>&nums, int target){
    int n = nums.size();
   int low =0;
   int high = n-1;
   while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]<target){
        low++;
    }
    else{
        high--;
    }
   }
   return -1;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<Search_X_Sorted(nums,k)<<" ";
    return 0;
}
