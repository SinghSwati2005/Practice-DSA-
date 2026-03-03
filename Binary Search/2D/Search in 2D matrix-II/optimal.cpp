#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool search(vector<vector<int>>&mat , int target){
int n = mat.size();
int m = mat[0].size();
int row = 0, col = m - 1;
while (row < n && col >= 0){
   
    if(mat[row][col]==target) return true;
    else if(mat[row][col]>target) col--;
    else row++;
}
return false;

}

int main(){
    int n ,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
     cout<<(search(matrix,k)? "True" : "False")<<" ";
    return 0;

}