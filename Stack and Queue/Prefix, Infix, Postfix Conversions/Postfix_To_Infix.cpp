#include<iostream>
#include<stack>
using namespace std;

string PostixToInfix(string s){
    stack<string>st;
   
   for(int i =0;i<s.length();i++){
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
    string expr = "(" + op2 + c + op1 + ")";
            st.push(expr);
    }

   }
   return st.top();
   
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "Infix expression: " << PostixToInfix(prefix) << endl;
    return 0;
}

