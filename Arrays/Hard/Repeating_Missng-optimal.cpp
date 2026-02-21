/* Input:
 nums = [3, 5, 4, 1, 1]  
Output:
 [1, 2]  
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].

Example 2:
Input:
 nums = [1, 2, 3, 6, 7, 5, 7]  
Output:
 [7, 4]  
Explanation:
 7 appears twice in the array, and 4 is missing from the array. So the output is [7, 4]. */


#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int>rm(vector<int>&nums){
int n = nums.size();
sort(nums.begin(),nums.end());
vector<int>res;
unordered_map<int,int>mpp;
int count =-1;
int missing =0;
for(int i=0;i<n-1;i++){
     mpp[nums[i]]++;
    if(nums[i+1]!=nums[i]+1){
        missing =   nums[i]+1;
    }
}
for(auto &it :mpp){
    if(it.second==2){
        res.push_back(it.first);
    }
    

}

res.push_back(missing);
return res;
}
int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];

    }
    
    vector<int>res = rm(nums);
    for(int x:res){
        cout<< x <<" ";
    }
    return 0;
}