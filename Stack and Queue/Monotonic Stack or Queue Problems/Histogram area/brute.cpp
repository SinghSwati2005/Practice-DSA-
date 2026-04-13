#include<iostream>
#include<vector>
#include<stack>
#include <climits>
using namespace std;

int largestarea(vector<int>&nums , int n){
    int maxArea =0;
    for(int i =0;i<n;i++){
        int minheight = INT_MAX;
        for(int j = i;j<n;j++){
            minheight = min(minheight, nums[j]);

            int width = j-i+1;
            int area = width*minheight;
            maxArea  = max(maxArea, area);
        }

    }
    return maxArea;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    int area = largestarea(nums,n);
    cout<<area<<" ";
    return 0;
}