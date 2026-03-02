/* Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output :True.
Explanation :The target = 8 exists in the 'mat' at index (1, 3).

Input :mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output :false.
Explanation :The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool search(vector<vector<int>>&matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
        
    }
    return false;
}

int main(){
    int n ,m,target;
    cin>>n>>m>>target;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<(search(matrix,target)? "True" : "False")<<" ";
    return 0;
}