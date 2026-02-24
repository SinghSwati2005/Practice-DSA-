// Input: N = 4, a[] = {7, 15, 6, 3}, h = 8
// Output: 5
// Explanation:  If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.
// Input: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
// Output: 25
// Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly.

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

bool possible(vector<int> &nums, int day, int m, int k)
{
    int cnt = 0;
    int nob = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= day)
        {
            cnt++;
        }
        else
        {
            nob += (cnt / k);
            cnt = 0;
        }
    }
    nob += (cnt / k);
    return nob >= m;
}

int bouquets(vector<int> &bloomDay, int m, int k)
{
    if (1LL * m * k > bloomDay.size())
        return -1;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int x : bloomDay)
    {
        mini = min(mini, x);
        maxi = min(maxi, x);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }
    cout << bouquets(bloomDay, m, k) << endl;
    return 0;
}