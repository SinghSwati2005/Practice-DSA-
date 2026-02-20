/* Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.
Input : [[1,4],[4,5]]
Output :  [[1,5]]
Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5]. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<vector<int>> mergeoverlap(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < n)
    {
        int start = nums[i][0];
        int end = nums[i][1];

        int j = i + 1;
        while (j < n && nums[j][0] <= end)
        {
            end = max(end, nums[j][1]);
            j++;
        }
        res.push_back({start, end});
        i = j;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    vector<vector<int>> result = mergeoverlap(nums);
    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}
