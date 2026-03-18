#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int n = s.length();
    int i = 0;
    int sign = 1;
    long long ans = 0; // use long long for overflow check

    // skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // check sign
    if (i < n && s[i] == '+') {
        i++;
    } else if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    }

    // convert digits
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');

        if (ans * sign <= INT_MIN) return INT_MIN;
        if (ans * sign >= INT_MAX) return INT_MAX;

        i++;
    }

    return (int)(ans * sign);
}

int main() {
    string s;
    getline(cin, s); // read full line including spaces
    cout << myAtoi(s) << endl;
    return 0;
}
