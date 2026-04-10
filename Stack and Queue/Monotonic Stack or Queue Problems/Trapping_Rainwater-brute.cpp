
// Input : height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output : 6
// Explanation : Water is trapped in the dips between bars. The total trapped water units add up to 6 (1+1+2+1+1).

// Input : height = [4,2,0,3,2,5]
// Output : 9
// Explanation : The elevation map traps 9 units of water in total, as water fills the spaces between higher bars on both sides.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Trapping_Rainwater_brute(vector<int>&h){
    int n = h.size();
    int total =0;
    for(int i =0;i<n;i++){
        int maxl = 0;
        int maxR = 0;
      for(int j =0;j<=i;j++){
        if(h[j]> maxl){
            maxl = h[j];
        }
      }

      for(int j =i;j<n;j++){
        if(h[j]> maxR){
            maxR = h[j];
        }
      }
      total += min(maxl, maxR)-h[i];
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i =0;i<n;i++){
        cin>>height[i];

    }
   int res = Trapping_Rainwater_brute(height);
    cout<<res<<" ";
    return 0;

}
