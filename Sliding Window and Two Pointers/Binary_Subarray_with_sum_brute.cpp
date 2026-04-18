#include<iostream>
#include<vector>
using namespace std;

int binary_subarray_sum(vector<int>&nums , int goal){
    int n = nums.size();
    
    int cnt = 0;
    for(int i =0;i<n;i++){
        int sum =0;
        for(int j =i;j<n;j++){
           
                sum+=nums[j];
                if(sum==goal){
              cnt++;
                }
             
           
        }
    }
    return cnt;

    
}

int main(){
    int n;
    cin>>n;
    int goal;
    cin>>goal;

    vector<int>nums(n);

    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<binary_subarray_sum(nums,goal)<<" ";
    return 0;
}