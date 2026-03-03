/* 240. Search a 2D Matrix II

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool binarySearch(vector<int>&nums,int target){
    int n = nums.size();
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return true;
        }
        else if(nums[mid]>target){
           high = mid - 1;

        }
        else{
           low = mid + 1;
        }
    }
    return false;
}
bool search (vector<vector<int>>&mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
         if(mat[i][0]<=target &&target<=mat[i][m-1]){
        if (binarySearch(mat[i],target)) return true;
       }
           
    }
    return false;
}


int main(){
    int n ,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
     cout<<(search(matrix,k)? "True" : "False")<<" ";
    return 0;

}