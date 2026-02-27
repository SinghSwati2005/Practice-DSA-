/* Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}.  */

 #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool CanWePlace(vector<int>& stalls, int cows, int d) {
    int count = 1;
    int last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= d) {
            count++;
            last = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

int Aggressive_cows(vector<int>& stalls, int cows) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int maxDist = stalls[n-1] - stalls[0];
    int ans = 0;
    for (int d = 1; d <= maxDist; d++) {
        if (CanWePlace(stalls, cows, d)) {
            ans = d;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Aggressive_cows(nums, k) << " ";
    return 0;
}
