#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
   vector<vector<int>>res;
   sort(nums.begin(),nums.end());
   for(int i =0;i<n;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;

    int j =i+1, k=n-1;
    while(j<k){
        int sum = nums[i]+nums[j]+nums[k];
        if(sum<0){
            j++;
        }
        else if(sum>0){
            k--;
        }
        else{
            res.push_back({nums[i],nums[j],nums[k]});
            j++;
            k--;
            while(j<k && nums[j]==nums[j-1])
            j++;
        }
    }
   }
   return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> res = threeSum(nums);

    for (auto &triplet : res) {
        cout << "[";
        for (int j = 0; j < triplet.size(); j++) {
            cout << triplet[j];
            if (j < triplet.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
