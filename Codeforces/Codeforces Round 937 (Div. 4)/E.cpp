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


vector<bool> prime(200001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    for (int i = 1; i <= 200000; i++) {
        prime[i] = true;
    }

    prime[0] = 0;
    prime[1] = 0;

    for (int k = 2; k <= 200000; k++) {
        if (prime[k]) {
            for (int h = k * 2; h <= 200000; h = h + k) {
                prime[h] = false;
            }
        }

        if (prime[k] == 0) {
            continue;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        string s;
        cin >> s;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1]) cnt++;
            if (cnt == 2) {
                flag = true;
                break;
            }
        }
        if (flag && prime[a]) {
            cout << a << "\n";
            continue;
        }



    }

    return 0;
}
