#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int temp = (s[0] - '0') * 10 + (s[1] - '0');
        if (temp == 0 || temp ==24) {
            cout << 12 << s[2] << s[3] << s[4] << " AM\n";
        } else if (temp == 12) {
            cout << s << " PM\n";
        } else if (temp > 12 && temp < 22) {
            cout << "0" << temp - 12 << s[2] << s[3] << s[4] << " PM\n";
        } else if (temp >= 22) {
            cout << temp - 12 << s[2] << s[3] << s[4] << " PM\n";
        } else {
            cout << s << " AM\n";
        }
    }

    return 0;
}
