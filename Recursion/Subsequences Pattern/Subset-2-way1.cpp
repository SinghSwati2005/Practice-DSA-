#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void helper(vector<int>&nums, int index , int sum , vector<int>&curr , vector<vector<int>>&res){
    if(index==nums.size()){
        res.push_back(curr);
return;
    }
    
    helper(nums, index+1, sum , curr, res);
    
    
    curr.push_back(nums[index]);
    helper(nums, index+1, sum , curr, res);
curr.pop_back();
}
 
vector<vector<int>>subset2(vector<int>&nums){
   
    vector<vector<int>>res;
    vector<int>curr;

    helper(nums,0,0,curr,res);
  sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>ans= subset2(nums);
    for(int i =0;i<ans.size();i++){
        cout<<"[";
        for(int j =0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";

        }
        cout<<"]\n";
    }
    return 0;
}