/* Input: M = 3, N = 3, matrix[][] =

1 4 9 
2 5 6
3 8 7
Output: 5
Explanation: 
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5

Input: M = 3, N = 3, matrix[][] =

1 3 8 
2 3 4
1 2 5
Output: 3
Explanation: 
If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. Therefore, median = 3. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countLessEqual(vector<int>& row , int target){
    return upper_bound(row.begin(),row.end(),target) - row.begin();
}
int findMedian(vector<vector<int>>&matrix , int m ,int n){
    int minVal = matrix[0][0];
    int maxVal = matrix[0][n-1];
    for(int i=1;i<m;i++){
        minVal = min(minVal , matrix[i][0]);
        maxVal = max(maxVal, matrix[i][n-1]);

    }
    int desired = (m*n+1)/2;
    while(minVal<maxVal){
        int mid = (minVal+maxVal)/2;
        int count =0;
        for(int i=0;i<m;i++){
            count += countLessEqual(matrix[i],mid);


        }
        if(count<desired){
            minVal = mid+1;

        }
        else{
            maxVal = mid;
        }

    }
    return minVal;
}

int main(){
    int m ,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
     cout<<findMedian(matrix,m,n)<<" ";
    return 0;

}