#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int helper (int ind , vector<int>&nums, int k){
if(ind ==0) return 0;

int minSteps = INT_MAX;
for(int j=1;j<=k;j++){
    if(ind-j>=0){
    int jump = helper(ind-j, nums ,k)+abs(nums[ind]-nums[ind-j]);
    minSteps = min(minSteps,jump);
}
}
return minSteps;
}




int frogjump(vector<int>&nums, int k){
    int n = nums.size();
  return   helper(n-1, nums,k);
}


int main() {
    int n,k;
    cin >> n>>k;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << frogjump(height,k) << endl;
    return 0;
}
