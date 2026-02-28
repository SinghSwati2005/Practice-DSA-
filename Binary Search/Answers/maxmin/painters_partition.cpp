/* Example 1:
Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result: 60
Explanation: We can divide the first 3 boards for one painter and the last board for the second painter. */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countPainters(vector<int>&nums, int time){
    int  n = nums.size();
    int painters =1;
    int boardsPainter =0;
    for(int i=0;i<n;i++){
        if(boardsPainter+nums[i]<=time){
            boardsPainter+= nums[i];
        }
        else{
            painters++;
            boardsPainter= nums[i];
        }
    }
    return painters;
}

int findLargestMinDist(vector<int>&nums, int n , int k){
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid = (low+high)/2;

        if(countPainters(nums,mid)>k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findLargestMinDist(nums, n ,k)<<" ";
    return 0;
}