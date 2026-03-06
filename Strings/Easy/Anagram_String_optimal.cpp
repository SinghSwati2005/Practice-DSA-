#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool anagram(string &s , string &x){
    if(s.length()!=x.length()) return false;
    int freq[26]={0};



    for(int i =0 ; i<s.length() ; i++){
       freq[s[i]-'A']++;
    }

    for(int i=0;i<x.length();i++){
freq[x[i]-'A']--;

    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0)
        return false;
    }
    return true;
}
int main(){
    string s,x;
    cin>>s>>x;
    cout<<anagram(s,x)<<" ";
    return 0;
}