/* Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer. */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
int maxcnt =0;
int rowIndex =-1;

for(int i=0;i<n;i++){
    int cnt =0;
    for(int j=0;j<m;j++){
        if(matrix[i][j]==1){
            cnt++;
        }
    }
    if(cnt>maxcnt){
        maxcnt = cnt;
        rowIndex =i;
    }
}
return rowIndex;
}


int main(){
    int n , m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<rowWithMax1s(matrix,n,m)<<" ";
    return 0;
}