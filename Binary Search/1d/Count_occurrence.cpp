/* Example 1:
Input:
N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
3 is occurring 4 times in
the given array so it is our answer.

Example 2:
Input:
N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
2 is occurring 5 times in the given array so it is our answer. */

#include <iostream>
#include <vector>
using namespace std;
int first_occur(vector<int> &nums, int x)
{
    
       int n = nums.size();
       int low =0;
       int high = n-1;

    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==x){
            ans = mid;
            high = mid-1;
        }
    else if(nums[mid]>x)
   { high = mid-1;}
    else{
        low = mid+1;
    }
    }
   
    return ans;
}
int last_occur(vector<int> &nums, int x)
{
    
       int n = nums.size();
       int low =0;
       int high = n-1;

    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==x){
            ans = mid;
            low = mid+1;
        }
    else if(nums[mid]>x)
   { high = mid-1;}
    else{
        low = mid+1;
    }
    }
   
    return ans;
}

int count_occur(vector<int>&nums, int x){
    int first = first_occur(nums,x);
    if(first ==-1) return 0;
    int last = last_occur(nums,x);
    return last -first+1;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << count_occur(nums, x) << " ";
    return 0;
}