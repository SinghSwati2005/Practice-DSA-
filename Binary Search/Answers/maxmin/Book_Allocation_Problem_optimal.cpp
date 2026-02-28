#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countStudents(vector<int>&nums, int pages){
    int n = nums.size();
    int students =1;
    int PS = 0;
    for(int i=0;i<n;i++){
        if(PS+ nums[i]<=pages){
            PS+=nums[i];
        }
        else{
            students++;
            PS = nums[i];
        }
    }
    return students;
}
int findPages(vector<int>&nums,int n , int m){
    if(m>n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        if( countStudents(nums, mid) > m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int main(){
    int n , m;
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<findPages(nums, n, m)<<" ";
    return 0;
}