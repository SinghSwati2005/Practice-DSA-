// Example 1:
// Input Format:arr[] = [1,0,-1,0,-2,2], target = 0
// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Explanation:We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int>> four_Sum(vector<int>&nums, int target){
int n = nums.size();

set<vector<int>> st;
for(int i=0;i<n;i++){
    for(int j =i+1;j<n;j++){
        for(int k = j+1;k<n;k++){
            for(int l = k+1;l<n;l++){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                   vector<int>res= {nums[i],nums[j],nums[k],nums[l]};
sort(res.begin(),res.end());
st.insert(res);
                }

            }
        }
    }
    
}
return vector<vector<int>>(st.begin(), st.end());

}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>>res = four_Sum(nums,target);
    for (auto &quad : res) {
        cout << "[";
        for (int j = 0; j < quad.size(); j++) {
            cout << quad[j];
            if (j < quad.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
