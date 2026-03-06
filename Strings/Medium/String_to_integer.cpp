#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0;          // only one declaration
    int sign = 1;
    long ans = 0;

    // skip leading spaces
    while (i < s.length() && s[i] == ' ')
        i++;

    // check sign
    if (i < s.length() && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < s.length() && s[i] == '+') {
        i++;
    }

    // convert digits
    while (i < s.length()) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            // handle overflow
            if (ans > INT_MAX && sign == -1)
                return INT_MIN;
            else if (ans > INT_MAX && sign == 1)
                return INT_MAX;

            i++;
        } else {
            return ans * sign;
        }
    }
    return ans * sign;
}

int main() {
    string s;
    getline(cin, s);   // read full line including spaces
    cout << myAtoi(s) << endl;
    return 0;
}
