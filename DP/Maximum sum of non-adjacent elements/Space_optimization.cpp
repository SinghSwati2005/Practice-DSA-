#include<bits/stdc++.h>
using namespace std;

int maxadj(vector<int>&nums){

 int n = nums.size();
  if (n == 1) return nums[0];
   

   int prev = nums[0];
   int prev2 = prev;

   for(int i =1;i<nums.size();i++){
 int pick = nums[i] ;
 if(i>1){
    pick +=prev2;
 }
   int notpick = 0+ prev;
   int curr =  max(pick , notpick);
   prev2= prev;
   prev = curr;
   }


  
   return prev;

}



int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }

    cout<<maxadj(nums)<<" ";
    return 0;
}