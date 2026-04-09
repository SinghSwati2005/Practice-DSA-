#include<iostream>
#include<stack>
using namespace std;

string prefixToPostfix(string s){
    stack<string>st;
    for(int i = s.length()-1 ; i>=0;i--){
        char c = s[i];

        if(c>='a'&& c<='z' ||
        c>='A'&& c<='Z'||
    c>='0'&& c<='9'){
        st.push(string(1, c));
    
    }
    else{
        string op1 = st.top();
        st.pop();
        string op2 = st.top();
        st.pop();
        string expr =  op1 + op2 + c ;
        st.push(expr);
    }
   
    
    }
     return st.top();
}


int main(){
    string s;
    cin>>s;
    cout<<prefixToPostfix(s)<<"";
    return 0;
}