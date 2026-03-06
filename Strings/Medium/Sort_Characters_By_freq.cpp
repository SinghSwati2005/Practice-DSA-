// Example 1:
// Input:
//  s = "tree"
// Output:
//  ['e', 'r', 't']
// Explanation:

// e → 2
// r → 1
// t → 1
// Since 'r' and 't' have the same frequency, they are sorted alphabetically → 'r' comes before 't'.

// Example 2:
// Input:
//  s = "raaaajj"
// Output:
//  ['a', 'j', 'r']
// Explanation:

// a → 4
// j → 2
// r → 1
// Characters are sorted by decreasing frequency. In case of ties, alphabetically.
 
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    // Step 1: Count frequency of each character
   unordered_map<char,int> freq;
           for(char c : s){
            freq[c]++;
           } 
           int  n = s.size();
           vector<vector<char>> buckets(n+1);
           for (auto it = freq.begin(); it != freq.end(); ++it) {
            char ch = it->first;
            int count = it->second;
            buckets[count].push_back(ch);
        }
           string result = "";
           for(int i =n ; i>=1; i--){
            for(char ch : buckets[i]){
                result += string (i,ch);
            }
           }
           return result;

}

int main() {
    string s;
    cin >> s;

    cout << frequencySort(s) << endl;
    return 0;
}
