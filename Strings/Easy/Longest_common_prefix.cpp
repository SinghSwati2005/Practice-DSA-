/* Example 1
Input:
 str = ["flower", "flow", "flight"]
Output:
 "fl"
Explanation:
 All strings in the array begin with the common prefix "fl".

Example 2
Input:
 str = ["apple", "banana", "grape", "mango"]
Output:
 ""
Explanation:
 None of the strings share a common starting sequence, so the result is an empty string.
             */

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string longest_common(vector<string>& nums ){
if(nums.empty()) return "";
sort(nums.begin(),nums.end());
string first = nums[0];
string last = nums[nums.size()-1];
string ans = "";
int minLength =  min(first.size(),last.size());
for(int i=0;i<minLength;i++){
    if(first[i]!=last[i]) break;
    ans+= first[i];
}
return ans;

}
int main(){
    int n;
    cin>>n;
    vector<string>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<longest_common(nums)<<" ";
    return 0;
}