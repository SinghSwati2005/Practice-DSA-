#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_next_permutation(vector<int>& nums) {
    // Use STL next_permutation directly
    if (next_permutation(nums.begin(), nums.end())) {
        return nums;   // next permutation exists
    } else {
        sort(nums.begin(), nums.end()); // reset to smallest if no next
        return nums;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = get_next_permutation(nums);
    for (int i : res) cout << i << " ";
    return 0;
}
