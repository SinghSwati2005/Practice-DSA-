#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int atmost(vector<int> &nums, int goal)
{
    int l = 0;
    int r = 0;
    int n = nums.size();
    int sum = 0;
    int cnt = 0;
    while (r < n)
    {
        sum += nums[r];
        if (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int binary_subarray_sum(vector<int> &nums, int goal)
{
    int n = nums.size();

    if (goal < 0)
        return 0;
    return atmost(nums, goal) - atmost(nums, goal - 1);
}

int main()
{
    int n;
    cin >> n;
    int goal;
    cin >> goal;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << binary_subarray_sum(nums, goal) << " ";
    return 0;
}