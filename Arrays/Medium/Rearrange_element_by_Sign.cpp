#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> Rearrange_sign(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;

    // Collect positives and negatives separately
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    // Alternate: positive first, then negative
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        res.push_back(pos[i++]);  // positive
        res.push_back(neg[j++]);  // negative
    }

    // If extras remain
    while (i < pos.size()) res.push_back(pos[i++]);
    while (j < neg.size()) res.push_back(neg[j++]);

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = Rearrange_sign(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
