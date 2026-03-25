#include <iostream>
#include <vector>
using namespace std;

void solve(int row, int col, vector<vector<int>>& grid, int n,
           string path, vector<string>& res) {
    if (row == n - 1 && col == n - 1) {
        res.push_back(path);
        return;
    }

    // mark visited
    grid[row][col] = 0;

    // Down
    if (row + 1 < n && grid[row + 1][col] == 1)
        solve(row + 1, col, grid, n, path + "D", res);

    // Left
    if (col - 1 >= 0 && grid[row][col - 1] == 1)
        solve(row, col - 1, grid, n, path + "L", res);

    // Right
    if (col + 1 < n && grid[row][col + 1] == 1)
        solve(row, col + 1, grid, n, path + "R", res);

    // Up
    if (row - 1 >= 0 && grid[row - 1][col] == 1)
        solve(row - 1, col, grid, n, path + "U", res);

    // unmark (backtrack)
    grid[row][col] = 1;
}

vector<string> findPath(vector<vector<int>>& grid, int n) {
    vector<string> res;
    if (grid[0][0] == 0) return res; // start blocked
    solve(0, 0, grid, n, "", res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<string> res = findPath(grid, n);
    if (res.empty()) cout << "No path exists\n";
    else {
        for (auto &p : res) cout << p << " ";
        cout << endl;
    }
    return 0;
}
