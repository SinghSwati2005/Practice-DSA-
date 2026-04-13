#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int>findNSE(vector<int>&nums){
int n = nums.size();
stack<int>st;
vector<int>ans(n,n);
for(int i = n-1;i>=0;i--){
    while(!st.empty() && nums[st.top()]>=  nums[i]){
        st.pop();
    }
    ans [i] = st.empty() ? n : st.top();
    st.push(i);
}
return ans;
}
vector<int>findPSE(vector<int>&nums){
int n = nums.size();
stack<int>st;
vector<int>ans(n,-1);
for(int i = 0;i<n;i++){
    while(!st.empty() && nums[st.top()]>  nums[i]){
        st.pop();
    }
    ans [i] = st.empty() ? -1 : st.top();
    st.push(i);
}
return ans;
}


int largestarea(vector<int>&nums){
    int n = nums.size();
    vector<int>nse = findNSE(nums);
    vector<int>pse = findPSE(nums);
int maxarea = 0;
    for(int i =0;i<n;i++){
    int width = nse[i] - pse[i]-1;
    int area = width* nums[i];
    maxarea = max(maxarea, area);
    }
    return maxarea;
}


int maxRectangle(vector<vector<int>>&mat){
    int  n = mat.size();
    int  m = mat[0].size();
    vector<int>height(m,0);
    int maxarea =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) height[j] +=1;
            else height[j]=0;
        }
        maxarea = max(maxarea,largestarea(height));

    }
    return maxarea;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
  vector<vector<int>> nums(n, vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
cin>>nums[i][j];
        }
    }

    cout<<maxRectangle(nums)<<" ";
    return 0;
}
