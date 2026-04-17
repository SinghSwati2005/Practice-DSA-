#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int fruit_in_basket(vector<int>&nums){
    int n = nums.size();
  int last =-1;
  int secondL = -1;
  int currlen = 0, maxlen =0;
  int lastFruitstreak =0;

  for(int i =0;i<n;i++){
    if(nums[i]==last || nums[i]==secondL){
        currlen++;
    }
    else{
        currlen = lastFruitstreak +1;
    }

    if(nums[i]==last){
        lastFruitstreak++;
    }
    else{
        lastFruitstreak=1;
        secondL = last;
        last = nums[i];
    }
    maxlen = max(maxlen, currlen);

  }
  return maxlen;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<fruit_in_basket(nums)<<" ";
    return 0;
}