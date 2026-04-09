#include <iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char>st;


    for(int i =0;i<s.length();i++){


        if(s[i]=='(' || s[i]=='{'|| s[i]=='['){
            st.push(s[i]);
        }
        if(s[i]==')' || s[i]=='}'|| s[i]==']'){
            if(st.empty()){
                return false;
            }
            else{

                char top = st.top();
                st.pop();
                if(s[i]==')' && top != '(' || s[i]=='}' && top!='{'|| s[i]==']' && top!='[')
                {
                   return false;
                }
            }  
            
        }

    }

    if(!st.empty()) return false;
    else  return true;
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if (isValid(s)) {
        cout << "The string is valid (balanced)." << endl;
    } else {
        cout << "The string is NOT valid (unbalanced)." << endl;
    }

    return 0;
}