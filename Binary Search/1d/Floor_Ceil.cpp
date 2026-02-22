/* Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
             */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int floor(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int ceil(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &nums, int x)
{
    int fIdx = floor(nums, x);
    int cIdx = ceil(nums, x);
    int f = (fIdx == -1 ? -1 : nums[fIdx]);
    int c = (cIdx == -1 ? -1 : nums[cIdx]);
    return make_pair(f, c);
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

    pair<int, int> ans = getFloorAndCeil(nums, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
}
