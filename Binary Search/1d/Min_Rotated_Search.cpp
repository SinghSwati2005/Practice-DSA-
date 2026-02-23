/* Input: arr = [4,5,6,7,0,1,2,3]
Output: 0
Explanation: The minimum element in the array is 0.
Input : arr = [3,4,5,1,2]
Output: 1
Explanation : The minimum element in the array is 1. */

#include<iostream>
#include<vector>
using namespace std;
int min_rotate(vector<int>&nums){
    int n = nums.size();
    int low =0;
    int high = n-1;
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid]>nums[high]){
            low = mid+1;
        }
        else{
            high = mid;
        }

    }
    return nums[low];
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }   

    cout<<min_rotate(nums)<<" ";
    return 0;
}