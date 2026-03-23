#include<iostream>
#include<vector>
using namespace std;

void solve(int col, vector<string>& board, int n,
           vector<int>& leftrow, vector<int>& upperdiagonal,
           vector<int>& lowerdiagonal, vector<vector<string>>& res) {
    if(col == n) {
        res.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0) {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdiagonal[row+col] = 1;
            upperdiagonal[n-1+col-row] = 1;

            solve(col+1, board, n, leftrow, upperdiagonal, lowerdiagonal, res);

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerdiagonal[row+col] = 0;
            upperdiagonal[n-1+col-row] = 0;
        }
    }
}

vector<vector<string>> nqueen(int n) {
    vector<vector<string>> res;
    vector<string> board(n);
    string s(n, '.');
    for(int i = 0; i < n; i++) board[i] = s;

    vector<int> leftrow(n, 0), upperdiagonal(2*n-1, 0), lowerdiagonal(2*n-1, 0);
    solve(0, board, n, leftrow, upperdiagonal, lowerdiagonal, res);
    return res;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<string>> ans = nqueen(n);

    cout << "Input: n = " << n << "\n";
    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << "\"" << ans[i][j] << "\"";
            if (j != n - 1) cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]\n";

    cout << "Explanation: There exist " << ans.size()
         << " distinct solutions to the " << n
         << "-queens puzzle as shown above\n";

    return 0;
}
