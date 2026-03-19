#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
    res.push_back(curr); // add current subset

    for(int i = index; i < nums.size(); i++) {
        if(i > index && nums[i] == nums[i-1]) continue; // skip duplicates
        curr.push_back(nums[i]);
        helper(nums, i+1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> subset2(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sort first to handle duplicates
    vector<vector<int>> res;
    vector<int> curr;
    helper(nums, 0, curr, res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> ans = subset2(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}
