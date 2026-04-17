#include <iostream>
#include <vector>
using namespace std;

int longest_Sub(vector<int>& nums, int k) {
    int n = nums.size();
    int maxlen = 0;
int l =0;

int zero=0;
    for (int r = 0; r < n; r++) {
     
       if(nums[r]==0) zero++;
       while(zero>k){
        if(nums[l] ==0) zero--;
        l++;
       }
      
        maxlen = max(maxlen , r-l+1);
     
       
    }
    return maxlen;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << longest_Sub(nums, k) << " ";
    return 0;
}
