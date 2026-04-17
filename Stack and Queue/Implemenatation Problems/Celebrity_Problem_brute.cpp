#include<iostream>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>&nums){
    int n = nums.size();
    vector<int>iknowj(n,0);

    vector<int>jknowi(n,0);

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
             if(nums[i][j]==1){
                iknowj[j]++;
                jknowi[i]++;
             }
        }
    }


    for(int i =0;i<n;i++){
        if(iknowj[i] == n-1 && jknowi[i]==0){
            return i;
        }
    }
    return -1;
}


int main(){ 
    int n ;
    cin>>n;
vector<vector<int>> mat(n, vector<int>(n));


    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<celebrity(mat)<<" ";
    return 0;

}
