#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nge2(vector<int>&nums){
int n = nums.size();
stack<int>st;
vector<int>ans(n,-1);


for(int i = 2* n-1;i>=0;i--){
    int ind = i%n;
    int curr = nums[ind];

    while(!st.empty()&& st.top()<=curr){
        st.pop();

    }
    if(i<n){
        if(!st.empty()){
            ans[ind] = st.top();

        }
    }

    st.push(curr);
}
return ans;
}


 int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    vector<int>res = nge2(nums);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
 }

