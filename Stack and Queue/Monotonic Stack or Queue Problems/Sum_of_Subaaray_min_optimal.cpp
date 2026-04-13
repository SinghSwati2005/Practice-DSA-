#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

vector<int> findNSE(vector<int>&nums)
{
int n = nums.size();

vector<int>ans(n);
stack<int>st;

for(int i = n-1;i>=0;i--){
    int curr = nums[i];
    while(!st.empty() && nums[st.top()]>= nums[i]){
        st.pop();
    }
    ans[i] = !st.empty()? st.top() :n;
    st.push(i);
}
return ans;




}


vector<int> findPSEE(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int> st;
    for(int i =0;i<n;i++){
        int curr = nums[i];

        while(!st.empty() && nums[st.top()]> nums[i]){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() :-1;
        st.push(i);
    }
    return ans;
}

int sumSubMin(vector<int>&nums){
    vector<int> nse = findNSE(nums);
    vector<int>psee = findPSEE(nums);
    int n = nums.size();
    int mod = 1e9 +7;
    int sum =0;
    for(int i =0;i<n;i++){
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right* 1LL;

        int val = (freq*nums[i]*1LL) % mod;
        sum = (sum+val) % mod;
    }
    return sum;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    int res = sumSubMin(nums);
    cout<<res<<" ";
    return 0;
}