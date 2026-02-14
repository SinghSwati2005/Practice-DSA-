#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Leaders_in_array(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    int lead = nums[n - 1];
    res.push_back(lead);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > lead)
        {
            res.push_back(nums[i]);
            lead = nums[i];
        }
    }
    reverse(res.begin(), res.end()); 
    return res;

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
    vector<int> result = Leaders_in_array(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
