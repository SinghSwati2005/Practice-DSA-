/* Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
Result: 3
Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

Example 2:
Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
Result: 2
Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int sumbyD(vector<int>&nums , int div){
     int n = nums.size();
    int sum =0;
    for(int i=0;i<n;i++){
       
        sum+=ceil((double)nums[i]/div);

    }
    return sum;
}





int divisor(vector<int> &nums, int limit)
{
   if(nums.size() > limit) return -1;
   int low =1;
    int high =0;
    for (int i = 0; i < nums.size(); i++)
    {
         high = max(high, nums[i]);
    }
    int res = high;
    while(low<=high){
        int mid = (low+high)/2;
        if(sumbyD(nums,mid)<=limit){
            high = mid-1;
        }
        else{
            low = mid+1;
        
        }
    }
    return low;
}

int main()
{
    int n, limit;
    cin >> n >> limit;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << divisor(arr, limit) << endl;
    return 0;
}