// Input :matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output :
// matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Rotate_matrix(vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> rotated(m, vector<int>(n)); // rotated is m x n

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][n - i - 1] = nums[i][j]; // ✅ correct assignment
        }
    }
    return rotated;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> result = Rotate_matrix(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
