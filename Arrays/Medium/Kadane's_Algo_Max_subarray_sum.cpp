#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int kadanes_algorithm(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;
    int maxi = INT_MIN;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    cout << "Maximum Subarray: ";
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
   cout << "Maximum Sum = " << kadanes_algorithm(nums) << endl;
    return 0;
}