#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>power_set(vector<int>&nums){
    int n = nums.size();
    int subsets = 1 <<n;
    vector<vector<int>>ans;
    for(int num =0;num<subsets;num++){
        vector<int>subset;
        for(int i = 0;i<n;i++ ){
            if(num &(1<<i)){
            subset.push_back(nums[i]);
            }
            

        }
        ans.push_back(subset);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i =0;i<n;i++){
        cin>>nums[i];

    }

    vector<vector<int>>res = power_set(nums);
    
    cout<<"[";
    for(int i =0;i<res.size();i++){
        cout<<"[";
        for(int j =0;j<res[i].size();j++){
            cout<<res[i][j];
           if (j < res[i].size() - 1) cout << ",";
        }
         cout<<"]";
         if (i < res.size() - 1) cout << ",";
    }
     cout<<"]";
}