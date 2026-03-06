/* Example 1:
Input:
 s = "rotation", goal = "tionrota"
Output:
 true
Explanation:
 After multiple left shifts on "rotation", we get:
    1st shift → "otationr"
    2nd shift → "tationro"
    3rd shift → "ationrot"
    4th shift → "tionrota"
    So the goal string can be obtained by rotating the original string.

Example 2:
Input:
 s = "hello", goal = "lohelx"
Output:
 false
Explanation:
 
Even after all possible rotations of "hello", we cannot form "lohelx" due to the presence of an extra character 'x'. Hence, it's not possible. */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool rotate(string &s , string &goal){
    if(s.length()!=goal.length()){
        return false;
    }
    for(int i=0;i<s.length();i++){
        string rotated = s.substr(i)+s.substr(0,i);
        if(rotated==goal){
            return true;

        }
    }
    return false;
}
int main(){
    string s,goal;
    cin>>s>>goal;
    cout<<rotate(s,goal)<<" ";
return 0;
    
}
