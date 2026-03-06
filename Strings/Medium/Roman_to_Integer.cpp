// Example 1:
// Input:
//  s = "LVIII"
// Output:
//  58
// Explanation:
//  L = 50, V= 5, III = 3.

// Example 2:
// Input:
//  s = "MCMXCIV"
// Output:
//  1994
// Explanation:
//  M = 1000, CM = 900, XC = 90 and IV = 4.
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
int romanToInt(string s){
    int res =0;
     unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for(int i=0;i<s.size()-1;i++){
            if(roman[s[i]]<roman[s[i+1]]){
                res-=roman[s[i]];
            }
            else{
                res+=roman[s[i]];
            }
        }
        return res+roman[s.back()];
}
int main(){
    string s;
    cin>>s;
    cout<<romanToInt(s)<<' ';
    return 0;
}