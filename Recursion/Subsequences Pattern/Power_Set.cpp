#include<iostream>
#include<vector>
using namespace std;

void helper(string &s , int index,string &curr, vector<string>&res ){
    if(index==s.size()){
        res.push_back(curr);
        return;
    }

    helper(s,index+1,curr,res);
    curr.push_back(s[index]);
    helper(s,index+1, curr,res);
    curr.pop_back();
}
vector<string>powerset(string s){
    vector<string>res;
    string curr = "";
    helper(s,0,curr,res);
    return res;
}

int main(){
    string s;
    cin>>s;
    vector<string>ans = powerset(s);
   for (int i = 0; i < ans.size(); i++) {
    cout << "\"" << ans[i] << "\"" << endl;
}

}
