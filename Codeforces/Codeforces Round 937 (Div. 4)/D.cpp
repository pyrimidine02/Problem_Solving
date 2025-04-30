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

vector<bool> prime(10000000);

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
    vi v;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    for (int m = 0; m < 2; ++m) {
                        int a = 10000 * i + 1000 * j + 100 * k + 10 * l + 1 * m;
                        if (a == 0 || a == 1) continue;
                        v.push_back(a);
                    }
                }
            }
        }
    }
    v.push_back(100000);

    while (t--) {
        int a;
        cin >> a;
        string s = to_string(a);
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "YES\n";
            continue;
        }
        int temp = a;
        for (auto i: v) {
            if (i > a) break;
            if (a % i == 0) {
                while (temp % i == 0) {
                    temp /= i;
                }
                a = temp;
            }
        }
        if (a != 1) {
            cout << "NO\n";
        } else cout << "YES\n";
    }

    return 0;
}
