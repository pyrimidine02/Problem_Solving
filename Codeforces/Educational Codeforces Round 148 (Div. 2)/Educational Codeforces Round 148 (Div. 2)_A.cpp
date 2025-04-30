#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() <= 3) {
            cout << "NO\n";
            continue;
        }
        int t = 0;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[0]) {
                cout << "YES\n";
                break;
            }
            t++;
        }
        if (t == s.size() / 2) cout << "NO\n";
    }

    return 0;
}