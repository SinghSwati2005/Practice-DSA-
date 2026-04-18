#include<iostream>
#include<vector>
#include <set>
#include <unordered_map>
using namespace std;

int char_substring(string s){
    int n = s.length();
    
     int cnt =0;
int l =0;
int  r=0;
unordered_map<char,int>mpp;
while(r<n){
    mpp[s[r]-'a']++;

    while(mpp[0]>0 && mpp[1]>0 && mpp[2]>0){
        cnt+=(n-r);
        mpp[s[l]-'a']--;
        l++;
    }
    r++;

   
}

return cnt;
}

int main()
{
    string s;
    cin>>s;
    cout<<char_substring(s)<<" ";
    return 0;
}