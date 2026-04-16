#include<iostream>
#include<vector>
using namespace std;

vector<int> StockSpan(vector<int>&nums, int n){
    vector<int>ans(n);
    for(int i =0;i<n;i++){
        int currspan =0;
        for(int j =i;j>=0;j--){
            if(nums[j]<= nums[i] ){
                currspan++;
            }
            else break;
        }
        ans[i] = currspan;
    }
    return ans;
}

int main(){
    int n , N;
    cin>>n>>N;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans = StockSpan(nums,N);
    for(int i =0;i<n;i++){
cout<<ans[i]<<" ";
    }
    return 0;
}