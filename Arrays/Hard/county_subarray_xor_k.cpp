/* Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9] */


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int xorsub(vector<int>&nums, int k){
    int n = nums.size();
    unordered_map<int,int>mpp;
   int rxor =0;
    int count=0;
    for(int i=0;i<n;i++){
     
        rxor = rxor^nums[i];
        if(rxor==k){
            count++;
        }
        int target = rxor^k;
        if(mpp.find(target)!=mpp.end()){
            count +=mpp[target];
        }
        mpp[rxor]++;
    }
    return count;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<xorsub(nums,k)<<" ";
    return 0;
}