#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
using namespace std;

string removeKDigits(string nums, int k){
    stack<char>st;

    for(int i =0;i<nums.size();i++){
        while(!st.empty() && k>0 && st.top()>nums[i]){
            st.pop();
            k--;
        }
        st.push(nums[i]);
    }

    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return "0";

    string res = "";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    while(res.size()>0 && res.back()=='0'){
   res.pop_back();
    }
    reverse(res.begin(),res.end());
    if(res.empty()) return "0";
    return res;

}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
   
   
    string ans = removeKDigits(s,k);
    cout<<ans<<" ";
    return 0;

}