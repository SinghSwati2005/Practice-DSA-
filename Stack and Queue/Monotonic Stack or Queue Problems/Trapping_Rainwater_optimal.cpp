#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int trap(vector<int>&height){
    int n = height.size();
    int left =0;
    int right = n-1;
    int maxl = 0;
    int maxr = 0;
    int totalWater = 0;

    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>= maxl){
                maxl = height[left];

            }
            else{
                totalWater += maxl - height[left];
            }
            left++;
        }



        else{
            if(height[right] >= maxr){
                maxr = height[right];
            }
            else{
                totalWater += maxr - height[right];
            }
            right--;
        }   
    }
return totalWater;
}

int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i = 0; i < n; i++){
        cin>>height[i];
    }
    int res = trap(height);
    
    cout<<res<<" ";
    return 0;
}




