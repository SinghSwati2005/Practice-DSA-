#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int celebrity(vector<vector<int>>&nums){
int n = nums.size();
int top =0 , down = n-1;
while(top<down){
    if(nums[top][down]==1){
        top++;
    }
    else if(nums[down][top]==1){
        down--;
    }
    else{
        top++;
        down--;
    }


}

if(top>down) return -1;
for(int i =0;i<n;i++){
    if(i== top) continue;

    if(nums[top][i]==1 || nums[i][top]==0){
return -1;
    }
}
return top;

}

int main(){
    int n ;
    cin>>n;
    vector<vector<int>>M(n,vector<int>(n));
 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    cout << celebrity(M) << endl;
    return 0;
}