#include<iostream>
#include<vector>
using namespace std;

int longest_Sub(string s){
    int n  = s.length();
     int maxlen = 0; 
   int l =0 ;
  
  vector<int>hash(256,-1);
   for(int r =0;r<n;r++){
    if(hash[s[r]] !=-1) {
        l = max(l,hash[s[r]]+1);
    }
    hash[s[r]] = r;
   int len = r-l+1;
    maxlen = max(maxlen,len);
   }

    return maxlen;
}

int main(){
    string n;
    cin>>n;

    cout<<longest_Sub(n)<<" ";
    return 0;

    
    
}