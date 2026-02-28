/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. */



 
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

double findMedian(vector<int>&nums1, vector<int>&nums2){
    int m = nums1.size();
    int n = nums2.size();
    if(m>n) return findMedian(nums2,nums1);

    int low =0;
    int high = m;
    while(low<=high){
        int cut1 = (low+high)/2;
        int cut2= (m+n+1)/2-cut1;

        int l1 = (cut1==0)? INT_MIN : nums1[cut1-1];
        int l2 = (cut2==0)? INT_MIN : nums2[cut2-1];
        int r1 = (cut1==m)? INT_MAX : nums1[cut1];
        int r2 = (cut2==n)? INT_MAX : nums2[cut2];

        if(l1<=r2 && l2<=r1){
            if((m+n) %2==0) return (max(l1,l2)+min(r1,r2))/2.0;
            else return max(l1,l2);

        }
        else if(l1>r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 0.0;
} 


int main(){
    int m , n ;
    cin>>m>>n;
    vector<int>nums1(m);

    for(int i =0;i<m;i++){
        cin>>nums1[i];
    }
    vector<int>nums2(n);
    for(int i =0;i<n;i++){
        cin>>nums2[i];
    }
    cout<<findMedian(nums1,nums2)<<" ";
    return 0;
}