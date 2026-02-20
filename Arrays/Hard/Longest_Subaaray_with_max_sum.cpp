// Example 1:
// Input:
//  N = 6, array[] = {9, -3, 3, -1, 6, -5}  
// Result:
//  5  
// Explanation:
//  The following subarrays sum to zero:
// - {-3, 3}
// - {-1, 6, -5}
// - {-3, 3, -1, 6, -5}
// The length of the longest subarray with sum zero is 5.



#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int max_subarray(vector<int>&nums){
    int n = nums.size();
    int maxi = 0;
    int sum =0;
   unordered_map<int,int> sumIndex;
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
          sum += nums[i];
       
            
            if(sum==0){
               
               
               maxi = max(maxi,i+1);
            
        }
        if(sumIndex.find(sum)!= sumIndex.end()){
maxi = max(maxi,i-sumIndex[sum]);
        }
        else{
            sumIndex[sum]=i;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<max_subarray(nums)<<" ";
    return 0;
}