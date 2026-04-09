#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>NSE(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>res(n,-1);

    for(int i = n-1;i>=0;i--){
        while(!st.empty()&& st.top()>=nums[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i] = st.top();
        }
        
            st.push(nums[i]);
        
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    vector<int>res = NSE(nums);
    for(int i =0;i<n;i++){
        cout<<res[i]<<" ";

    }
    return 0;

}
