// Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.

// Example 1

// Input : s = "aabaa"

// Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] , [ "aa", "b", "aa" ] , [ "aabaa" ] ]

// Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

// Example 2

// Input : s = "baa"

// Output : [ [ "b", "a", "a"] , [ "b", "aa" ] ]

// Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void helper(string s, int index, vector<string> &curr, vector<vector<string>> &res) {
    if (index == s.size()) {
        res.push_back(curr);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (isPalindrome(s, index, i)) {
            curr.push_back(s.substr(index, i - index + 1));
            helper(s, i + 1, curr, res);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> curr;
    vector<vector<string>> res;
    helper(s, 0, curr, res);
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<vector<string>> ans = partition(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}
