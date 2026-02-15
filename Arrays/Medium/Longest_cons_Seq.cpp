// Example 1:
// Input:
//  nums = [100, 4, 200, 1, 3, 2]  
// Output:
//  4  
// Explanation:
//  The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// Example 2:
// Input:
//  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
// Output:
//  9  
// Explanation:
//  The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_consecutive(vector<int>&nums){
    int n = nums.size();
    sort(nums.begin(),nums.end()); // 1 2 3 4 100 200
    int count =1;
    int longest=1;
    for(int i=1;i<n;i++){
      if(nums[i]==nums[i-1]){
       continue;
      }
      if(nums[i]==nums[i-1]+1){
        count++;
      }
      else{
        count =1;
      }
      longest = max(longest,count);
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<longest_consecutive(nums)<<" ";
    return 0;
}