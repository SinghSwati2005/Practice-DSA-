 #include<iostream>
 #include<stack>
#include <vector>
 using namespace std;

vector<int> NGE (vector <int>&nums){
 stack<int>st;
 vector<int>res(nums.size(),-1);
 for(int i =nums.size()-1;i>=0;i--){
    if(!st.empty() && st.top()<=nums[i]){
        st.pop();
    }
        if(!st.empty()){
            res[i]=st.top(); 
            
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
    vector<int>res = NGE(nums);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
 }