/* Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 

Example 2:
Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result: 1
Explanation: One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this. */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip> 
using namespace std;

long double GasStation(vector<int>& nums, int k){
    int n = nums.size();
    vector<int>howmany(n-1,0);
    for(int gasStations = 1; gasStations <=k;gasStations++){
        long double maxSection = -1;
        int maxIndex = -1;

        for(int i =0;i<n-1;i++){
            long double  diff = nums[i+1]-nums[i];
            long double  sectionLength = diff/ (howmany[i]+1.0);
            if(sectionLength>maxSection){
                maxSection = sectionLength;
                maxIndex =i;
            }
        }
        howmany[maxIndex]++;

    }
    long double maxAns =-1;
    for(int i= 0;i<n-1;i++){
        long double diff = nums[i+1]- nums[i];
        long double sectionLength = diff/(howmany[i]+1.0);
        maxAns = max(maxAns, sectionLength);

    }
    return maxAns;
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout << fixed << setprecision(6);
     cout << GasStation(nums, k) << "\n";
    return 0;
}