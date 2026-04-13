#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>findNSE(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =n-1;i>=0;i--){
while(!st.empty()&& nums[st.top()]>= nums[i]){
    st.pop();

}
ans[i] = st.empty()? n : st.top();
st.push(i);
    }
    return ans;
}


vector<int> findPSEE (vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
       
        while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;

}

vector<int> findNGE (vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i = n-1;i>=0;i-- ){
        if(!st.empty() && nums[st.top()]<=nums[i]){
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findPGEE (vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n);

    for(int i = 0;i<n;i++ ){
        if(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int minS(vector<int>&nums){
    vector<int>nse = findNSE(nums);
    vector<int>psee = findPSEE(nums);
    vector<int>nge = findNGE(nums);
    vector<int>pgee = findPGEE(nums);
    int n = nums.size();
    int sum =0;
    for(int i =0;i<n;i++){
      int left = i - psee[i];
      int right = nse[i] - i;
sum += (long long)left * right * nums[i];

    }
    return sum;
}
int maxS(vector<int>&nums){
    vector<int>nse = findNSE(nums);
    vector<int>psee = findPSEE(nums);
    vector<int>nge = findNGE(nums);
    vector<int>pgee = findPGEE(nums);
    int n = nums.size();
    int sum =0;
    for(int i =0;i<n;i++){
      int left = i - pgee[i];
      int right = nge[i] - i;
sum += (long long)left * right * nums[i];

    }
    return sum;
}

int range(vector<int>&nums){
    int n = nums.size();
    int mini = minS(nums);
    int maxi = maxS(nums);
    int range = maxi - mini;
    return range;
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i =0 ; i<n;i++){
        cin>>nums[i];
    }
    int ans = range(nums);
    cout<<ans<<" ";
    return 0;
}