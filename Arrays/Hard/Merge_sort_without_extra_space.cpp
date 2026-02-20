/* Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2 */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;        // last valid element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last position in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining nums2 elements
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;
    cin >> m >> n;  // m = number of valid elements in nums1, n = size of nums2

    vector<int> nums1(m + n);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    for (int x : nums1) {
        cout << x << " ";
    }
    return 0;
}
