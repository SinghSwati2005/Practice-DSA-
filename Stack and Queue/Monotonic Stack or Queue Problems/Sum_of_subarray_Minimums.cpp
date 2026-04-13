#include<iostream>
#include<vector>
#include <climits>
using namespace std;


int sum_of_subarray_min(vector<int>&nums){
    int n = nums.size();
    
       int sum =0;
    for(int i =0;i<n;i++){
     
        int mini =INT_MAX;
        for(int j =i ;j<n;j++){
            
            
            mini = min(mini,nums[j]);
            sum+=mini;
        }
    }
    return sum;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << sum_of_subarray_min(nums) << endl;
    return 0;
}

