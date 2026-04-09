#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {
    // Step 1: Reverse the infix string
    reverse(s.begin(), s.end());

    // Step 2: Swap brackets
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Operand
        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')) {
            res += c;
        }
        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        // Operator
        else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    getline(cin, exp);

    cout << "Prefix expression: " << infixToPrefix(exp) << endl;
    return 0;
}
