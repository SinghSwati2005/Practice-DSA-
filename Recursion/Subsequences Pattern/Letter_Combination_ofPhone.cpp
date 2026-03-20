#include<iostream>
#include<vector>
using namespace std;
void helper(int index, string digits, string s, vector<string>&res,string combo[])
{
    if(index==digits.size()){
   res.push_back(s);
   return;
    }

    int digit = digits[index]-'0';
    for(int i=0;i<combo[digit].size();i++){
        helper(index+1,digits,s+combo[digit][i],res,combo);
    }
}

vector<string>lettercombo(string digits){
    string combo[]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>res;
    string s = "";
    helper(0,digits,s,res,combo);
    return res;
}

int main(){
    string s;
    cin>>s;
    vector<string>res = lettercombo(s);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
