/* 
Example 1:
Input : 
start = 10 , goal = 7
Output :
 3
Explanation :
 The binary representation of 10 is "1010". The binary representation of 7 is "111". If we flip the underlined bits in binary representation of 10 then we will obtain our goal.

Example 2 :
Input :
 start = 3 , goal = 4
Output :
 3
Explanation :
 The binary representation of 3 is "011".The binary representation of 4 is "100". So if we flip all the three bits of 3 then we will reach our goal number.
 */


#include<iostream>
#include <vector>
using namespace std;


int single_element(vector<int>&arr){
    int  n = arr.size();
    int xorr = 0;
    for(int i =0;i<n;i++){
        xorr = xorr^ arr[i];

    }
    return xorr;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
       cin>>arr[i];
        }
         cout<<single_element(arr)<<" ";
   
  
    return 0;
}