//print the subse also

#include<iostream>
#include<vector>
using namespace std;

void helper(int index, int sum , int target, int &cnt, vector<int>&nums, vector<int>&curr,vector<vector<int>>&res){
    if(index==nums.size()){
        if(sum==target && !curr.empty()){
            res.push_back(curr);
            cnt++;
            
        }
        return;
    }

    helper(index+1, sum , target,cnt, nums, curr, res);
   curr.push_back(nums[index]);
    helper(index+1, sum+ nums[index] , target,cnt, nums, curr, res);
curr.pop_back();
}

pair<vector<vector<int>>, int>count(vector<int>&nums,int k){
    vector<vector<int>>res;
    vector<int>curr;
    int cnt =0;
    helper(0,0,k,cnt,nums,curr,res);
    return {res,cnt};
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];

    }
    pair<vector<vector<int>>,int> result = count(nums,k);
    vector<vector<int>>res = result.first;
    int cnt = result.second;

for (int i = 0; i < res.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]\n";
    }

    cout << "Count = " << cnt << endl;

    return 0;
}
