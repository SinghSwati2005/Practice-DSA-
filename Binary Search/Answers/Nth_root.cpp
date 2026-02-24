// Input: N = 3, M = 27
// Output: 3
// Explanation: The cube root of 27 is equal to 3.
// Input : N = 4, M = 69
// Output: -1
// Explanation : The 4th root of 69 does not exist. So, the answer is -1




#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int find_nth_root( int n, int m){
   
     int low =0;
     int high = m;
   
     while(low<=high){
        int mid = low+(high-low)/2;
        long long power = pow(mid,n);
        if(power == m) {
            return mid;
        }
      else   if(power<m){
          
            low = mid+1;
        }
        else{
            high = mid-1;
        }
     }
    

return -1;

}
int main(){
    int n, m;
    cin>>n>>m;
   

    cout<<find_nth_root(n,m)<<" ";
    return 0;
}
