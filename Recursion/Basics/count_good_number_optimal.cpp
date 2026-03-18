#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
long long recurse(long long index, long long n)
{
    long long  res = 1;
    index = index%MOD;
     while(n>0){
        if(n%2==1){
            res = (res* index)%MOD;
        }
        index = (index*index)%MOD;
        n/=2;
     }
     return res;
}

int good_number(long long n)
{
   long long even = (n + 1) / 2;
    long long odd = (n) / 2;
    return (recurse(5, even) * recurse(4, odd)) % MOD;
}


int main() {
    int n;
    cin >> n;   // user only inputs length
    cout << good_number(n) << endl;
    return 0;
}