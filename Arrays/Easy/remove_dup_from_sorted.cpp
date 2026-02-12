#include<iostream>
#include<vector>
using namespace std;
int removeduplicates_from_sorted(vector<int> &nums){
    int n = nums.size();
    int k =0;
    for(int i =1;i<n;i++)
{
    if(nums[i]!=nums[k]){
        k++;
        nums[k]=nums[i];
    }
    
}
return k+1;
}

int main(){
    int n; 
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result= removeduplicates_from_sorted(nums);
    cout<<result<<endl;
    for(int i=0;i<result;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
