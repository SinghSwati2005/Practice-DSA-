/* Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
             */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lower_bound(vector<int>&nums, int N , int x){
    int low=0;
    int high = N-1;
    int ans = N;
    while(low<=high){
        int mid= (low+high)/2;
        if(nums[mid]>=x){
             ans = mid;
            high = mid-1;
        }
        
        else{
         low = mid+1;
        }
    }
    return ans;
}
int main(){
    int N,n,k;
    cin>>N>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }   

    cout<<lower_bound(nums,N,k)<<" ";
    return 0;
}
