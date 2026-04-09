#include<iostream>
#include<stack>
#include <vector>
using namespace std;

vector<int>NGE2(vector<int>& nums){
    stack<int>st;
    int  n = nums.size();
    vector<int>res(n,-1);

    for(int i = 0 ; i<n;i++){
        for(int j =1;j<n;j++){
            int ind = (j+i)%n;
           if(nums[i]<nums[ind]){
            res[i] = nums[ind];
            break;
           }
        }
       
    }
    return res;

}

 int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];

    }
    vector<int>res = NGE2(nums);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
 }