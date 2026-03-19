#include<iostream>
#include<vector>
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


    helper(nums, index+1,target,sum, curr , res);
    curr.push_back(nums[index]);
    helper(nums, index,target,sum+nums[index], curr , res);
    curr.pop_back();
    
}

vector<vector<int>>solve(vector<int>& nums, int k){
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