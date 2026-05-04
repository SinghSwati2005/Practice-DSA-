#include<iostream>
#include<vector>
using namespace std;

int max_point_obtain_cards(vector<int>&nums, int k ){
    int n = nums.size();
    int maxi=0;
    for(int i =0;i<=k;i++){
        int sum =0;
        for(int j =0;j<i;j++){
            sum+=nums[j];
        }

        for(int j =0;j<k-i;j++){
            sum+=nums[n-1-j];

        }
        maxi = max(maxi,sum);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    cout<<max_point_obtain_cards(nums,k)<<" ";
    return 0;
}