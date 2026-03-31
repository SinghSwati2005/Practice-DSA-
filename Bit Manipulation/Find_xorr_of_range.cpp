#include<iostream>
using namespace std;

int range(int L, int R){
    int xorr=0;
    for(int i =L;i<=R;i++){
     xorr = xorr^ i;
    }
    return xorr;
}

int main(){
    int L,R;
    cin>>L>>R;
    cout<<range(L,R)<<" ";
    return 0;
}