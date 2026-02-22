/* Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Result: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.
             */




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Search_insertion(vector<int>&nums, int x){
     int n = nums.size();
     int low =0;
     int high = n-1;
     int ans = n;
     while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]>=x){
            ans = mid;
            high = mid -1;
        }
       else{
        low = mid+1;
       }
     }
     return ans;



}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<Search_insertion(nums,k)<<" ";
    return 0;
}
