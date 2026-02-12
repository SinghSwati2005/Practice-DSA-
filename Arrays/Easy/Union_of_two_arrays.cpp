#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> Union_Of_TWO_ARRAY(vector<int> &nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    map<int, int>mpp;
    vector<int>res;
    for(int i=0;i<n;i++){
      mpp[nums1[i]]++;
    }
    for (int i=0;i<m;i++){
        mpp[nums2[i]]++;
    }

    for(auto &it :mpp){
        res.push_back(it.first);
    }
    return res;
}
int main(){
    int n , m;
    cin>>n;
    cin>>m;

    vector<int>nums1(n);
    vector<int>nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    vector<int>result = Union_Of_TWO_ARRAY(nums1, nums2);
    for(auto &it : result){
        cout<<it<<" ";
    }
}