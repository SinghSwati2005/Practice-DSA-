
// Input: N = 5, weights = [5, 4, 5, 2, 3, 4, 5, 6], d = 5
// Output: 9
// Explanation: The minimum ship capacity needed to ship all packages within 5 days is 9.

// Input: N = 3, weights = [1, 2, 3, 4, 5], d = 2
// Output: 9
// Explanation: With a capacity of 9, the packages can be shipped in 2 days as [1,2,3,4] and [5].

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

int dayscount(vector<int>&weight , int capacity){
int n = weight.size();
int days =1;
int load =0;
for(int i=0;i<n;i++){
    if(load +weight[i] >capacity){
        days++;
        load = weight[i];
    }
    else{
        load +=weight[i];
    }
}
return days;
}
int capacity(vector<int>&weight , int days){
    int n = weight.size();
    int low = *max_element(weight.begin(),weight.end());
   int high = accumulate(weight.begin(), weight.end(), 0);
    int ans = high;
    while(low<=high){
        int mid = (low+high)/2;
        if(dayscount(weight, mid)<=days){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}


int main() {
    int n, d;
    cin >> n >> d;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << capacity(weights, d) << endl;
    return 0;
}
