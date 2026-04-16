#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>>&nums){
    int n = nums.size();
    stack<int>st;
    for(int i =0;i<n;i++){
        st.push(i);
    }
    while(st.size() >1){
        int A = st.top(); st.pop();
        int B = st.top(); st.pop();

        if(nums[A][B] ==1){
            // A knows B → A cannot be celebrity
            st.push(B);
        }
        else{
             // A does not know B → B cannot be celebrity
            st.push(A);
        }
    }
    int cand = st.top();
    for(int i =0;i<n;i++){
        if(i==cand) continue;

        if(nums[cand][i]==1) return -1;
        if(nums[i][cand]==0) return -1;
    }
    return cand;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>M(n,vector<int>(n));

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>M[i][j];
        }
    }
    cout<<celebrity(M) <<endl;
    return 0;
}