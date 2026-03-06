// Example 1:
// Input:
//  s = "(1+(2*3)+((8)/4))+1"
// Output:
//  3
// Explanation:
//  Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input:
//  s = "(1)+((2))+(((3)))"
// Output:
//  3
// Explanation:
//  Digit 3 is inside of 3 nested parentheses in the string.


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int max_nesting_depth(string s){
    int count =0;
    int maxdepth =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            count++;
           
        }
        if(s[i]==')'){
            count--;
           
        }
         maxdepth = max(maxdepth,count);
    }
    return maxdepth;
}
int main(){
    string s;
    cin>>s;
    cout<<max_nesting_depth(s)<<" ";
    return 0;
}
