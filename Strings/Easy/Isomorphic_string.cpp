/* Example 1
Input:
 s = "paper", t = "title"
Output:
 true
Explanation:
 The characters in "s" can be mapped one-to-one to characters in "t": 
'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
Since the mapping is consistent and unique for each character, the strings are isomorphic.

Example 2
Input:
 s = "foo", t = "bar"
Output:
 false
Explanation:
 'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping. */

#include<iostream>
#include<string>
#include<map>
using namespace std;
bool isomorphic(string s , string t){
    if(s.length()!=t.length()) return false;
    map<char,char>mpp1,mpp2;
    for(int i=0;i<s.length();i++){
        char c1 = s[i] , c2= t[i];
       if(mpp1[c1]!=mpp2[c2]) return false;
       mpp1[c1]= i+1;
       mpp2[c2]= i+1;
    }
    return true;
    }
int main() {
    string s, t;
    cin >> s >> t;
    cout << (isomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}