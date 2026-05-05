#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&nums , int pivot, int left , int right){
int pivotres = nums[pivot];

swap(nums[left],nums[pivot]);
int ind = left +1;

for(int i =left +1;i<=right;i++){
    if(nums[i]>pivot){
        swap(nums[ind],nums[i]);
        ind++;
    }
}
swap(nums[left],nums[ind-1]);
return ind-1;
}

int randomeIndex(int & left , int &right){
int len = (right - left +1);
return (rand()% len)+left;
}


int kth_largest(vector<int>&nums , int k){
   
int n = nums.size();
if(k>n) return -1;

int left =0 ; int right = n-1;
while(true){
    int pivot = randomeIndex(left , right);

    pivot= partition(nums , pivot,left , right);


    if(pivot ==k-1) return nums[pivot];
    else if(pivot >k-1) right = pivot-1;
    else left = pivot +1;
}
return -1;
}

int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<kth_largest(nums,k);
    return 0;
}
