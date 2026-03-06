// Example 1:
// Input:
//  s = "pqpqs", k = 2  
// Output:
//  7  
// Explanation:
//   All substrings with exactly 2 distinct characters:  
// "pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"  
// Total = 7.

// Example 2:
// Input:
//  s = "abcbaa", k = 3  
// Output:
//  5  
// Explanation:
//   All substrings with exactly 3 distinct characters:  
// "abc", "abcb", "abcba", "bcba", "cbaa"  
// Total = 5.

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int atMostKDistinct(string s , int k){
    int left =0;
    int res =0;
    unordered_map<char,int>mpp;
    for(int right =0;right<s.size();right++){
        mpp[s[right]]++;
    
    while(mpp.size()>k){
        mpp[s[left]]--;
        if(mpp[s[left]]==0) mpp.erase(s[left]);
        left++;
    }
    res+=(right-left+1);
}
return res;
}

int countSubstrings(string s , int k){
    return atMostKDistinct(s,k)-atMostKDistinct(s,k-1);
    
}

int main(){
    string s;
    int k;
    cin>>s>>k;
    cout<<countSubstrings(s,k)<<" ";
    return 0;
}