#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int n) {
    vector<vector<int>> result;
    vector<int> prevRow;

    for (int i = 0; i < n; i++) {
        vector<int> currentRow(i + 1, 1); // initialize row with 1s

        for (int j = 1; j < i; j++) {
            currentRow[j] = prevRow[j - 1] + prevRow[j];
        }

        result.push_back(currentRow);
        prevRow = currentRow;
    }
    return result;
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    vector<vector<int>> result = pascal(N);

    // Print Pascal's Triangle
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // Print specific element (1-based indexing)
    if (r <= N && c <= result[r - 1].size()) {
        cout << "\nElement at row " << r << ", column " << c << " is: "
             << result[r - 1][c - 1] << endl;
    } else {
        cout << "\nInvalid row/column input!" << endl;
    }

    return 0;
}
