// // Input: arr[] = {1,2,3,4,5,6,7,8,5,1}
// Output: 7
// Explanation: There is only 1 peak element, 8,  that is at index 7.
// Input: arr[] = {1,2,1,3,5,6,4} 
// Output: 1 
// Explanation : There are 2 peak numbers that are at indices 1 and 5. We can return any of them.






#include<iostream>
#include<vector>
using namespace std;
int peak (vector<int>&nums)
{
    int n = nums.size();
    int low =0;
    int high = n-1;
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid]<nums[mid+1]){
          low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }   

    cout<<peak(nums)<<" ";
    return 0;
}
