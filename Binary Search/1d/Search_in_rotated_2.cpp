/* Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
Explanation: The element 3 is present in the array. So, the answer is True.

Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
Explanation: The element 10 is not present in the array. So, the answer is False.
 */
#include <iostream>
#include <vector>
using namespace std;
bool rotated(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == x)
        {
            return true;
        }
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }

        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= x && x <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else {
            if (nums[mid] < x && x <= nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        } 
    }
    return false;
}



int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << rotated(nums, x) << " ";
    return 0;
}