/* Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output :-1
Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1. */



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rotated(vector<int>&nums, int x){
    sort(nums.begin(),nums.end());
    int N = nums.size();
    int low=0;
    int high = N-1;
   
    while(low<=high){
        int mid= (low+high)/2;
        if(nums[mid]==x){
            return mid;
        }
        
        else if(nums[mid]<x){
         low = mid+1;
        }
        else {
            high = mid-1;
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

    cout<<rotated(nums,k)<<" ";
    return 0;
}
