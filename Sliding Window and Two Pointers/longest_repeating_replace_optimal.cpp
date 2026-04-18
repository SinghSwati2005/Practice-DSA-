#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_Sub(string nums, int k) {
    int n = nums.size();
    int maxlen = 0;
int l =0;
int r =0;
int maxfreq=0;

vector< int>mpp(26,0);

    while ( r  < n) {
     mpp[nums[r]-'A']++;

     maxfreq = max(maxfreq, mpp[nums[r]-'A']);
while((r-l+1 )-maxfreq>k){
    mpp[nums[l]-'A']--;
    l++;
}
      
        maxlen = max(maxlen , r-l+1);
     r++;
       
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


//O(1) space