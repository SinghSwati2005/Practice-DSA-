#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

vector<vector<int>> four_sum(vector<int>& nums, int target) {
    int n = nums.size();
    

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
