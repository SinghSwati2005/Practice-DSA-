#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool anagram(string &s , string &x){
    if(s.length()!=x.length()) return false;
    sort(s.begin(),s.end());
    sort(x.begin(),x.end());

    for(int i =0;i<s.length();i++){
        if(s[i]!=x[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s,x;
    cin>>s>>x;
    cout<<anagram(s,x)<<" ";
    return 0;
}