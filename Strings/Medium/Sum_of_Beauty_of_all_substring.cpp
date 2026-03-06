// Example 1:
// Input:
//  s = "xyx"
// Output:
//  1
// Explanation:
//  The substrings with non-zero beauty are:
// "xyx" → frequencies: x:2, y:1 → beauty = 2 - 1 = 1
// "xy" → x:1, y:1 → beauty = 0
// "yx" → y:1, x:1 → beauty = 0
// "x" or "y" → beauty = 0
// Total sum = 1 (from "xyx") = 1

// Example 2:
// Input:
//  s = "aabcbaa"
// Output:
//  17
// Explanation:
//  Various substrings such as "aabc", "bcba", etc., have non-zero beauty values. Summing all gives 17.

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include <climits>
using namespace std;
int sum_of_beauty_of_all_substring(string s){
    int sum =0;
    for(int i=0;i<s.length();i++){
        unordered_map<char,int>mpp;
        for(int j=i;j<s.length();j++){
              mpp[s[j]]++;
               int maxi = INT_MIN;
                int mini = INT_MAX;
              
          for(auto &it :mpp){
mini = min(mini,it.second);
maxi = max(maxi,it.second);
          } 
          sum+=(maxi-mini); 
    }
}
return sum;
}

int main(){
    string s;
    cin>>s;
    cout<<sum_of_beauty_of_all_substring(s)<<" ";
    return 0;
}