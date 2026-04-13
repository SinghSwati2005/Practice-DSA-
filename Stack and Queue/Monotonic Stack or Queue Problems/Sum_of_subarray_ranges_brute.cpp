// brute force 

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int range(vector<int>nums){
    int n = nums.size();
  
    int ans =0;
    for(int i =0;i<n;i++){
          int maxi =nums[i];
    int mini =nums[i];
         for (int j = i; j < n; j++) {
        maxi = max(maxi,nums[j]);
        mini = min(mini,nums[j]);
        ans += maxi - mini;
    }
}
    return ans;
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

