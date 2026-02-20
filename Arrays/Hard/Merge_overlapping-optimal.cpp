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
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
   for(int i=0;i<n;i++){
    if(ans.empty()|| nums[i][0]>ans.back()[1]){
        ans.push_back(nums[i]);
    }
    else{
        ans.back()[1] = max(ans.back()[1],nums[i][1]);
    }
   }
    return ans;
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
