#include<iostream>
#include<vector>
using namespace std;
void left_rotate_array(vector<int>&nums){
    int n = nums.size();
    int temp = nums[0]; /// we could have used temp = nums[n] buyt that malkes the space complexity to O(n) right now iot is O(1).
        for(int i =1;i<n;i++){
            nums[i-1]=nums[i];

        }
        nums[n-1]=temp;
    
  
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
     left_rotate_array(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
        
    }
    return 0;
}