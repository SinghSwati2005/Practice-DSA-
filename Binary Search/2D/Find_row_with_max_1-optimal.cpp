#include<iostream>
#include<vector>
using namespace std;

int lowerbound(vector<int> &row, int n) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] == 1) {
            ans = mid;
            high = mid - 1;  // look for earlier 1
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int rowwithMax1(vector<vector<int>> &mat, int n, int m) {
    int maxcnt = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int firstIndex = lowerbound(mat[i], m);
        if (firstIndex != -1) {
            int cnt = m - firstIndex;  // number of 1s in this row
            if (cnt > maxcnt) {
                maxcnt = cnt;
                index = i;
            }
        }
    }
    return index;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << rowwithMax1(matrix, n, m) << endl;
    return 0;
}
