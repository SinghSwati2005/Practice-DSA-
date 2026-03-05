#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string reverse(string s){
    vector<string> words;
    string word ="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        else if (!word.empty()){
            words.push_back(word);
            word="";
        }
    }
     if (!word.empty()) {
            words.push_back(word);
        }

 reverse(words.begin(), words.end());
    string res ="";
    for(int i=0;i<words.size();i++){
        res+=words[i];

        if(i<words.size()-1){
            res+=" ";
        }
    }
    return res;


}

int main() {
    string s;
    getline(cin, s);  // read full line including spaces
    cout << reverse(s) << endl;
    return 0;
}