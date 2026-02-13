#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int majority_element(vector<int>&nums){
    int n = nums.size();
    int count =0;
    int maxcount=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
                maxcount = max(maxcount,count);
            }
        }
    }
    return maxcount;
}
int main(){
   int n ;
    cin>>n;
    vector<int>nums(n);
   
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
 int result = majority_element(nums);
     
      cout<<result<<" ";
    
    
    return 0;  
}