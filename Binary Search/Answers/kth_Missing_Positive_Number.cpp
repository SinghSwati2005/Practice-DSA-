/* Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.

Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kth_missing_posi (vector<int>&nums , int k){
    int n = nums.size();
    int low =0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        int missing = nums[mid]-( mid+1);
        if(missing<k){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return low + k;
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<kth_missing_posi(nums, k)<<" ";

    return 0;

}