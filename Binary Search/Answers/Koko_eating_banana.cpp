// Input: N = 4, a[] = {7, 15, 6, 3}, h = 8
// Output: 5
// Explanation:  If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  
// Input: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
// Output: 25
// Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. 

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int koko(vector<int>&nums,  int h){
    int n = nums.size();
int low =1, high = 0;

     for(int i=0;i<n;i++){
        high = max(high , nums[i]);
     }
     int res = high;
     while(low<=high){
        int k = low + (high - low) / 2;
        long int hr =0;
        for(int i=0;i<n;i++){
            hr+=ceil((double) nums[i]/k);
        }
        if(hr<=h){
            res = min(res, k);
            high = k-1;
        }
        else{
            low = k+1;
        }
     }
     return res;
    
}

int main(){
    int n, h;
    cin>>n>>h;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
       
    }
     cout<<koko(nums, h)<< " ";
        return 0;
}