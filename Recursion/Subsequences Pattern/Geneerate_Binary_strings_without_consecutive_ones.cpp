#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generate( int  n , string curr , vector<string> & res){
    if((int)curr.size()==n){
        res.push_back(curr);
        return;
    }
    generate(n , curr+'0',res);

if(curr.empty()|| curr.back()=='0'){
    generate(n , curr+'1', res);
}
}

vector<string> generateBinaryStrings(int n){
    vector<string>res;
    generate(n,"",res);
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string>ans = generateBinaryStrings(n);
    for(string s : ans){
        cout<<s<<"\n";

    }
    return 0;
}