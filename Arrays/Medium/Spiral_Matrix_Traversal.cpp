// Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
// Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
// Explanation: The output of matrix in spiral form.


#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral_matrix(vector<vector<int>>& mat) {
    vector<int> result;
    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse left → right
        for (int i = left; i <= right; i++)
            result.push_back(mat[top][i]);
        top++;

        // Traverse top → bottom
        for (int i = top; i <= bottom; i++)
            result.push_back(mat[i][right]);
        right--;

        // Traverse right → left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result.push_back(mat[bottom][i]);
            bottom--;
        }

        // Traverse bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(mat[i][left]);
            left++;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> result = spiral_matrix(mat);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
