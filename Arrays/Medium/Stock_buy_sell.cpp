#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int stock_buy_sell(vector<int>&prices){
    int n = prices.size();
int maxi =0;
    int CP =0;
    int SP=0;
    for(int i=0;i<n;i++){
        CP = prices[i];
        for(int j =i+1;j<n;j++){
            SP = prices[j];
              int Profit = SP-CP;
        maxi = max(maxi, Profit);
        }
      
    }
    return maxi;
}

int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<stock_buy_sell(nums)<<" ";
return 0;
}