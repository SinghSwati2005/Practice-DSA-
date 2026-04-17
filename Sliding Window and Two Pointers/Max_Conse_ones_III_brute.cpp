#include <iostream>
#include <vector>
using namespace std;

int longest_Sub(vector<int>& nums, int k) {
    int n = nums.size();
    int maxlen = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int flip = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == 1) {
                cnt++;
            } else {
                if (flip < k) {   // corrected condition
                    cnt++;
                    flip++;
                } else {
                    break;        // stop if flips exceed k
                }
            }
            maxlen = max(maxlen, cnt);
        }
    }
    return maxlen;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << longest_Sub(nums, k) << " ";
    return 0;
}
