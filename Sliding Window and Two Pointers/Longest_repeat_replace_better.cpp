#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_Sub(string nums, int k) {
    int n = nums.size();
    int maxlen = 0;
int l =0;

int maxfreq=0;

unordered_map<char , int>mpp;

    for (int r = 0; r < n; r++) {
     mpp[nums[r]]++;

     maxfreq = max(maxfreq, mpp[nums[r]]);
while((r-l+1 )-maxfreq>k){
    mpp[nums[l]]--;
    l++;
}
      
        maxlen = max(maxlen , r-l+1);
     
       
    }
    return maxlen;
}

int main() {
      string nums;
    
 cin>>nums;
 int  k;
    cin >> k;

    cout << longest_Sub(nums, k) << " ";
    return 0;
}
//space O(26)