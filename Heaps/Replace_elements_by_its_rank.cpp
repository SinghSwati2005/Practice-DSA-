#include<bits/stdc++.h>
using namespace std;

vector<int> assign_rank(vector<int>&nums){
    int n = nums.size();
vector<int>res;
    for(int i =0;i<n;i++){
        unordered_set<int>st;
        for(int j =0;j<n;j++){
            if(nums[j]<nums[i]){
                st.insert(nums[j]);
                
            }
        
        }
            int rank =  st.size()+1;
                res.push_back(rank);

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
    vector<int>res = assign_rank(nums);
    for(int num : res){
        cout<<num<<" ";

    }
    return 0;
}
