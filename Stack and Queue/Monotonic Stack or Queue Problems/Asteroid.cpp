#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int>asteroid(vector<int>&nums){
    stack<int>st;
    
    for(int i =0;i<nums.size();i++){
         bool destroyed = false;



        while(!st.empty()  && nums[i]<0 && st.top()>0 ){
           if(st.top()<-nums[i]){
            st.pop();
            continue;
           } 
           else if(st.top()==-nums[i]){
            st.pop();
           }
           destroyed = true;
           break;
        }
        if(!destroyed){
            st.push(nums[i]);
        }

    }
    vector<int>res(st.size());
    for(int i = st.size() -1;i>=0;i--){
        res[i] = st.top();
        st.pop();
    }
    return res;
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    vector<int>ans = asteroid(nums);
    for(int x : ans){
        cout<<x <<" ";
       
    }
     return 0;
}
