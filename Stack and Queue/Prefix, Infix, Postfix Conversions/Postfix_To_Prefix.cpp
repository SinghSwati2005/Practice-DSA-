#include<iostream>
#include<stack>
using namespace std;

string postfixToPrefix(string s){
    stack<string>st;
    for(int i = 0 ; i<s.length();i++){
        char c = s[i];

        if(c>='a'&& c<='z' ||
        c>='A'&& c<='Z'||
    c>='0'&& c<='9'){
        st.push(string(1, c));
    
    }
    else{
        string op2 = st.top();
        st.pop();
        string op1 = st.top();
        st.pop();
        string expr = c+ op1 + op2  ;
        st.push(expr);
    }
   
    
    }
     return st.top();
}


int main(){
    string s;
    cin>>s;
    cout<<postfixToPrefix(s)<<"";
    return 0;
}