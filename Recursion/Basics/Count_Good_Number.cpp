#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int recurse(int index, int n)
{
    if (index == n)
    {
        return 1;
    }
    int res = 0;
    if (index % 2 == 0)
    {
        for (int digit : {0, 2, 4, 6, 8})
        {
            res = (res + recurse(index + 1, n)) % MOD;
        }
    }
    else
    {
        // Prime digits: 2, 3, 5, 7
        for (int digit : {2, 3, 5, 7})
        {
            res = (res + recurse(index + 1, n)) % MOD;
        }
    }
    return res;
}

int good_number(int n)
{
    return recurse(0, n);
}

int main() {
    int n;
    cin >> n;   // user only inputs length
    cout << good_number(n) << endl;
    return 0;
}