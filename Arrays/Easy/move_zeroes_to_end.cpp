#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void move_zeroes_to_end (vector<int> &nums){
    int n = nums.size();
    int k =0;
    for(int i =0;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[k]);
            k++;
        }
        
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    move_zeroes_to_end(nums);
    for(int i =0;i<n;i++){
        cout<<nums[i]<<" ";


    }
    return 0;

}