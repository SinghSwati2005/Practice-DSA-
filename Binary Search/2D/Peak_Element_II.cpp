#include <iostream>
#include <vector>
using namespace std;

// Find the row index of the maximum element in a given column
int findMaxIndex(vector<vector<int>>& mat, int n, int col) {
    int maxValue = mat[0][col];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

// Function to find a peak element
vector<int> peak(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1; // binary search on columns

    while (low <= high) {
        int mid = (low + high) / 2;
        int maxRow = findMaxIndex(mat, n, mid);

        int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

        if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
            return {maxRow, mid}; // peak found
        } else if (left > mat[maxRow][mid]) {
            high = mid - 1; // move left
        } else {
            low = mid + 1; // move right
        }
    }
    return {-1, -1}; // should not happen if input guarantees a peak
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

    vector<int> ans = peak(matrix);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}
