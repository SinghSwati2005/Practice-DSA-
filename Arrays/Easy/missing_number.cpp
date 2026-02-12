#include<iostream>
#include<vector>
using namespace std;
int missing_number(vector<int>&nums){
    int n = nums.size()-1;
    int sum =0;
    int total = (n * (n + 1)) / 2;
    for(int i =0;i<n-1;i++){
sum +=nums[i];

    }
    int res = total - sum;
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
   int result = missing_number(nums);
    cout<<result<<"";
    return 0;
}