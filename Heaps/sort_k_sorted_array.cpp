#include <bits/stdc++.h>
using namespace std;

vector<int> sortk(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push first k+1 elements
    for (int i = 0; i < min(k+1, n); i++) {
        pq.push(nums[i]);
    }

    // Process remaining elements
    for (int i = k+1; i < n; i++) {
        res.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }

    // Pop remaining elements
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> res = sortk(nums, k);
    for (int num : res) cout << num << " ";
    cout << "\n";
    return 0;
}


//Time: O(n log k)

//Space: O(k)