#include<iostream>
#include<vector>
#include <set>
using namespace std;

int char_substring(string s){
    int n = s.length();
    
     int cnt =0;
for(int i =0;i<n;i++){
   set<char>st;

    for(int j =i;j<n;j++){
        st.insert(s[j]);
        if(st.size()==3) cnt++;
        
    }
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