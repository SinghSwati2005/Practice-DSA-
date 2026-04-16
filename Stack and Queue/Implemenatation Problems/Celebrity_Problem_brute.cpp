#include<iostream>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>&nums){
    int n = nums.size();
    vector<int>knowme(n,0);

    vector<int>Iknow(n,0);

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
             if(nums[i][j]==1){
                knowme[j]++;
                Iknow[i]++;
             }
        }
    }


    for(int i =0;i<n;i++){
        if(knowme[i] == n-1 && Iknow[i]==0){
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
