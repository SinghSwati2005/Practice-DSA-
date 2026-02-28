#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int numberOfGasStationsRequired(long double dist,vector<int> &nums )
{
    int n = nums.size();
    int cnt = 0 ;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = (nums[i] - nums[i - 1]) / dist;
        if ((nums[i] - nums[i - 1]) == (dist * numberInBetween))
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double GasStations(vector<int> &nums, int k)
{
    int n = nums.size();
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(nums[i + 1] - nums[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2;
        int cnt = numberOfGasStationsRequired(mid, nums);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    long double ans = GasStations(nums, k);
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}