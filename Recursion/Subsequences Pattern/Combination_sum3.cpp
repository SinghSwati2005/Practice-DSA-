#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper(int index,int k , int target,vector<int>&curr,vector<vector<int>>&res){
    
        if( target == 0 && curr.size()==k  ){
   res.push_back(curr);
return;
        }
     
 // if (target <= 0 || curr.size() > k) return;

    for(int i=index;i<=9;i++){
    //    if (i > target) break;
        curr.push_back(i);
        helper(i+1,k,target-i,curr,res);
        curr.pop_back();
    }
}


vector<vector<int>>combination(int k , int n){
    vector<vector<int>> res;
    vector<int>curr;
    helper(1,k,n,curr,res);
    return res;
}


int main(){
    int k , n;
    cin>>k>>n;
     vector<vector<int>> ans = combination(k,n);
    for(int i = 0; i < ans.size(); i++) {
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}