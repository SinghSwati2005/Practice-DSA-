#include<iostream>
#include<vector>
#include<stack>
#include <climits>
using namespace std;

vector<int>NSE(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n,n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int>PSEE(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

int largestarea(vector<int>&nums , int n){
    
    vector<int>nse = NSE(nums);
    vector<int>pse = PSEE(nums);
    int maxarea =0;
    for(int i =0;i<n;i++){
        int width = nse[i] -pse[i] -1;
        int area = width * nums[i];
        maxarea = max(maxarea, area);
    }
    return maxarea;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    int area = largestarea(nums,n);
    cout<<area<<" ";
    return 0;
}