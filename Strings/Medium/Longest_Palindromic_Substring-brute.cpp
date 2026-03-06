#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string Longest_palindrome_substring(string s){
    int n = s.length();
    string longest = "";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string sub = s.substr(i,j-i+1);
            string rev = sub;
            reverse(rev.begin(),rev.end());
            if(sub==rev && sub.size()>longest.size()){
                longest = sub;
            }
        }
    }
    return longest;
}
int main(){
    string s;
    cin>>s;
    cout<<Longest_palindrome_substring(s)<<" ";
    return 0;
}