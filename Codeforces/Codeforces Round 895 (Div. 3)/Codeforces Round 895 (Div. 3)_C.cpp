#include <bits/stdc++.h>


using namespace std;

const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


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
        int l, r;
        cin >> l >> r;
        if (r < 4) {
            cout << -1 << "\n";
            continue;
        }
        if (r % 2 == 0) {
            cout << r / 2 << " " << r / 2 << "\n";
            continue;
        } else if (r != l) {
            cout << (r - 1) / 2 << " " << (r - 1) / 2 << "\n";
        } else {
            bool flag = false;
            for (int i = 2; i < min(r, 10000); ++i) {
                if (gcd(r, i) != 1) {
                    cout << r / i << " " << r / i * (i - 1) << "\n";
                    flag = true;
                    break;

                }
            }
            if (!flag)
                cout << "-1\n";

        }
    }


    return 0;
}