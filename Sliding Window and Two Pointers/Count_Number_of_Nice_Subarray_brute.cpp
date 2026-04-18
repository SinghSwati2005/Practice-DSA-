#include<iostream>
#include<vector>
using namespace std;

int nice_subarray_cnt(vector<int>&nums , int goal){
    int n = nums.size();
    
    int cnt = 0;
    for(int i =0;i<n;i++){
        int odd =0;
        for(int j =i;j<n;j++){
           
                
                if(nums[j]%2!=0){
              odd++;
                }
                if(odd==goal){
                    cnt++;
                }
                if(cnt>goal) break;
                
             
           
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
    cout<<nice_subarray_cnt(nums,goal)<<" ";
    return 0;
}