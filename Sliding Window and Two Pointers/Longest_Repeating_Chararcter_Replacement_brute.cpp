#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_repeat_replace(string s, int k) {
    int n = s.length();
    int maxlen = 0;

    // Try each character as the target
    for (char target = 'A'; target <= 'Z'; target++) {
        for (int i = 0; i < n; i++) {
            int flip = 0;
            int cnt = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == target) {
                    cnt++;
                } else if (flip < k) {
                    cnt++;
                    flip++;
                } else {
                    break; // exceeded k flips
                }
                maxlen = max(maxlen, cnt);
            }
        }
    }
    return maxlen;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << longest_repeat_replace(s, k) << " ";
    return 0;
}
