// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix..

// Examples
// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> set_zero_matrix(vector<vector<int>> &nums)

    {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> row(n, 1), col(m, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 0 || col[j] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
        return nums;
    }

    int main()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> nums(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }
        vector<vector<int>> result = set_zero_matrix(nums);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }