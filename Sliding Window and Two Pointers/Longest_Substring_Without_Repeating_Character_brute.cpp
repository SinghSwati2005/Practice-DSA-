#include<iostream>
#include<vector>
using namespace std;

int longest_Sub(string s){
    int n  = s.length();
     int maxlen = 0; 
    for(int i =0;i<n;i++){
         vector<int> hash(256, 0); 
       for(int j=i;j<n;j++){
        if(hash[s[j]]==1) break;
       
        hash[s[j]]=1;
       int len= j-i+1;
       maxlen = max(maxlen , len);
    }
}
    return maxlen;
}

int main(){
    string n;
    cin>>n;

    cout<<longest_Sub(n)<<" ";
    return 0;

    
    
}