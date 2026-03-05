/* Example 1:
Input:
 s = "((()))"
Output:
 "(())"
Explanation:
 The input string is a single primitive: "((()))".  
Removing the outermost layer yields: "(())".

Example 2:
Input:
 s = "()(()())(())"
Output:
 "(()())()"
Explanation:
 Primitive decomposition: "()" + "(()())" + "(())"  
After removing outermost parentheses: "" + "()()" + "()"
Final result: "(()())()" */

#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    string result = "";  
    int level = 0;       

    for (char ch : s) {
        if (ch == '(') {
            if (level > 0) result += ch;
            level++;  
        } else if (ch == ')') {
            level--;  
            if (level > 0) result += ch;
        }
    }
    return result;
}

int main() {
    string s;
    cin >> s;   // ✅ read the string once
    cout << removeOuterParentheses(s) << endl;
    return 0;
}



