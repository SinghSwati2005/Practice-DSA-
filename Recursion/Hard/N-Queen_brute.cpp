#include<iostream>
#include<vector>
using namespace std;

bool safe(int row, int col, vector<string>&board,int n)
{

        int duprow = row;
    int dupcol = col;
    while(row>=0&&col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
col = dupcol;
    row= duprow;

    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
row=duprow;
    col =dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string>&board,vector<vector<string>>&res, int n){
    if(col==n){
        res.push_back(board);
        return;
    }

    for(int row =0;row<n;row++){
      if(safe(row,col,board,n)){
        board[row][col]= 'Q';
        solve(col+1,board,res,n);
        board[row][col]= '.';
      }
    }
}




vector<vector<string>>nqueen(int n){
    vector<vector<string>>res;
    vector<string>board(n);
    string s(n,'.');
    for(int i =0;i<n;i++){
        board[i]=s;

    }
    solve(0,board,res,n);
    return res;
}


int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<string>> ans = nqueen(n);
cout << "[ ";
       for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j <n; j++) {
            cout << "\"" << ans[i][j] << "\"";
        if (j != n - 1) cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    return 0;
}

