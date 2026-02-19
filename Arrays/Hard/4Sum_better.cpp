#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

vector<vector<int>> four_sum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unordered_set<int> seen;
            for (int k = j + 1; k < n; k++) {
                int required = target - nums[i] - nums[j] - nums[k];
                if (seen.count(required)) {
                    vector<int> quad = {nums[i], nums[j], nums[k], required};
                    sort(quad.begin(), quad.end()); // sort quadruplet
                    st.insert(quad); // insert into set
                }
                seen.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> res = four_sum(nums, target);

    for (auto &quad : res) {
        cout << "[";
        for (int j = 0; j < quad.size(); j++) {
            cout << quad[j];
            if (j < quad.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
