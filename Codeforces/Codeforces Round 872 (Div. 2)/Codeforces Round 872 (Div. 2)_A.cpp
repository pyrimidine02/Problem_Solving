#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
int len;

bool pali(string s, int a, int b) {
    for (int i = 0; i < len; ++i) {
        if (a > b) return true;
        else if (s[a] != s[b]) return false;
        a++;
        b--;
    }
}

bool check(string s) {
    for (int i = 1; i < len; ++i) {
        if (s[i] != s[0]) return true;
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        len = a.length();
        if (pali(a, 0, len - 1)) {
            if (check(a)) {
                cout << len - 1 << "\n";
            } else cout << "-1\n";
        } else {
            cout << len << "\n";
        }
    }


    return 0;
}