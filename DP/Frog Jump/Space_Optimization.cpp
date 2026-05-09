#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size();
    
int prev = 0;
        int prev2 = 0;

        if (n == 1) return 0;
    for(int i = 1; i < n; i++) {
        int left = prev + abs(height[i] - height[i-1]);
        int right = INT_MAX;
        if(i > 1) {
            right = prev2 + abs(height[i] - height[i-2]);
        }
        int res = min(left, right);
        prev2 = prev;
        prev = res;
    }

    return prev;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << frogJump(height) << endl;
    return 0;
}
