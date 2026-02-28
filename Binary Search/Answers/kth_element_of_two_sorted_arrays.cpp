/* Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Examples
Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output:
 6  
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:
Input:
 a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output:
 256  
Explanation:
 The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256. */



 
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

double findkthelement(vector<int>&nums1, vector<int>&nums2, int k){
    int m = nums1.size();
    int n = nums2.size();
    if(m>n) return findkthelement(nums2,nums1,k);

    int low = max(0, k - m), high = min(k, n);
    while(low<=high){
        int cut1 = (low+high)/2;
        int cut2= k-cut1;

        int l1 = (cut1==0)? INT_MIN : nums1[cut1-1];
        int l2 = (cut2==0)? INT_MIN : nums2[cut2-1];
        int r1 = (cut1==m)? INT_MAX : nums1[cut1];
        int r2 = (cut2==n)? INT_MAX : nums2[cut2];

        if(l1<=r2 && l2<=r1){
           return max(l1,l2);
           

        }
        else if(l1>r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return -1;;
} 


int main(){
    int m , n ,k;
    cin>>m>>n>>k;
    vector<int>nums1(m);

    for(int i =0;i<m;i++){
        cin>>nums1[i];
    }
    vector<int>nums2(n);
    for(int i =0;i<n;i++){
        cin>>nums2[i];
    }
    cout<<findkthelement(nums1,nums2,k)<<" ";
    return 0;
}