// Input: N = 36
// Output: 6
// Explanation: Square root of 36 is 6. 
// Input: N = 28
// Output: 5
// Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.







#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_sqrt( int n){
   
     int low =0;
     int high = n/2;
     int ans =0;
     while(low<=high){
        int mid = low+(high-low)/2;
        if(mid*mid<=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
     }
    

return ans;

}
int main(){
    int n;
    cin>>n;
   

    cout<<find_sqrt(n)<<" ";
    return 0;
}
