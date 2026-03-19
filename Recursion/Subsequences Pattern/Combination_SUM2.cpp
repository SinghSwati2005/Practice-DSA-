// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]]
// Explanation: These are the unique combinations whose sum is equal to target.
 
// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: [[1,2,2],[5]]
// Explanation: These are the unique combinations whose sum is equal to target.
            #include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void helper(vector<int>& nums,int index,
    int target, int sum,vector<int>&curr,
    vector<vector<int>>& res){
 if(sum == target){
    res.push_back(curr);
    return;
}
if(index == nums.size() || sum > target){
    return;
}

for(int i =index;i<nums.size();i++){
    if(i>index && nums[i]==nums[i-1]) continue;
    //if(sum +nums[i]>target) break;

     curr.push_back(nums[i]);
    helper(nums, i+1,target,sum+nums[i], curr , res);
    curr.pop_back();
}  
}

vector<vector<int>>solve(vector<int>& nums, int k){
   sort(nums.begin(),nums.end());
    vector<int> curr;
   vector<vector<int>>res;
 helper(nums,0,k,0,curr,res);
 return res;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans = solve(nums,k);
for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }

   

    return 0;
}