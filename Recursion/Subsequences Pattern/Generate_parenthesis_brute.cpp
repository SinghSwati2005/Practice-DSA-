#include<iostream>
#include<vector>
using namespace std;
bool isvalid (string s){
    int cnt =0;
    for(char c =0;c<s.length();c++){
        if(s[c]=='(') cnt++;
        else cnt--;
        if(cnt<0) return false;

    }
    return cnt == 0;

}

void generateAll(string curr , int n, vector<string> &res){
    if(curr.length()==2*n){
       if (isvalid(curr)) res.push_back(curr);
        return;  
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string>res = generateParenthesis(n);
    for(string s : res){
        cout << s << endl;
    }
    return 0;
}