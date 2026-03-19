#include<iostream>
#include<vector>
using namespace std;

bool helper(vector<int>&nums, int index, int sum){
    if(index==nums.size()){
        return sum==0;
    }


    int exclude = helper(nums, index+1, sum);
    int include = helper(nums, index+1, sum-nums[index]);


return exclude + include;
}

bool check(vector<int>&nums, int k){
    return helper(nums, 0 , k);
}

int main(){
    int n, k;
    cin >> n >> k; 
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout<<(check(nums,k)? "true" : "false") <<endl;
}

