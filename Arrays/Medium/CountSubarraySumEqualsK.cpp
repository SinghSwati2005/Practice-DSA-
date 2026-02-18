// Input : N = 4, arrarray may[] = {3, 1, 2, 4}, k = 6
// Output: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

#include <iostream>
#include<vector>
using namespace std;

int count_subarray(vector<int>nums,int k){
    int n = nums.size();
   
    int count =0;
    for(int i=0;i<n;i++){
         int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum ==k){
                count ++;
            }
        }
    }
    return count;
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;

    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int res = count_subarray(nums,k);
    cout<<res<<" ";
    return 0;

}