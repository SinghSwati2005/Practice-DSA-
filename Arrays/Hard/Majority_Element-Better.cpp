#include <iostream>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> majority(vector<int> nums)
{
    int n = nums.size();
   unordered_map<int,int>mpp;
   vector<int>res;

    for (int i = 0; i < n; i++)
    {
      mpp[nums[i]]++;
    }

    for(auto &it : mpp){
        if(it.second >n/3){
            res.push_back(it.first);
        }

        if(res.size()==2) break;
    }
    
    
    sort(res.begin(), res.end());

    return res;
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

 vector<int>res = majority(nums);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
   
sort(res.begin(), res.end());
    return 0;
}