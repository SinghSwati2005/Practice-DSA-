#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sort_0_1_2 (vector<int>&nums){
    int n = nums.size();
    int left =0;
    int right = n-1;
    int mid =0;
    while(mid<=right){
        if(nums[mid]==0){
            swap(nums[mid],nums[left]);
            mid++;
            left++;
        }
        else if (nums[mid]==2){
            swap(nums[mid],nums[right]);
           
            right--;
        }
        else{
            mid++;
        }
       
    }
    
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
   
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
 sort_0_1_2(nums);
     for(int i =0;i<n;i++){
      cout<<nums[i]<<" ";
    }
    
    return 0;
}
