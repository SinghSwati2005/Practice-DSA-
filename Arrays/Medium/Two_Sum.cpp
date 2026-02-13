#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


bool two_sum(vector<int>& nums, int target){
   int n = nums.size();
   unordered_map<int , int>mpp;
  
   for(int i =0;i<n;i++){
    int sum = target-nums[i];
    if(mpp.find(sum)!=mpp.end())
    {return true;}
    mpp[nums[i]] = i;
   }
   
    return false;
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];

    }
    cout << (two_sum(nums, target) ? "Yes" : "No") << " ";
    return 0;
}