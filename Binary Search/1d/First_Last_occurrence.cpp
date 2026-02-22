/* Example 1:
Input:
 N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 4  
Explanation:
 The target value 13 appears for the first time at index number 2 in the array.  

Example 2:
Input:
 N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 -1  
Explanation:
 Target value 60 is not present in the array, so the output is -1. */

#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1; // keep searching left
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1; // keep searching right
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
