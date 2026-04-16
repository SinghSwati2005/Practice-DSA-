#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findPGE(vector<int>nums){
    int n = nums.size();
    vector<int>ans(n,-1);
stack<int>st;
    for(int i =0;i<n;i++){
 while(!st.empty() && nums[st.top()] <=nums[i] ){
    st.pop();
 }
 ans [i] = st.empty() ? -1  : st.top();
 st.push(i);
    }
return ans;
}


vector<int>stockspan(vector<int>nums,int n){
    vector<int>PGE = findPGE(nums);

    vector<int>ans(n);
    

    for(int i =0;i<n;i++){
        ans[i] = i-PGE[i];
    }
    return ans;
}


int main(){
    int n , N;
    cin>>n>>N;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans = stockspan(nums,N);
    for(int i =0;i<n;i++){
cout<<ans[i]<<" ";
    }
    return 0;
}