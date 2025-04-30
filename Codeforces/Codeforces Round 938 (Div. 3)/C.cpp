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
        ll a, b;
        cin >> a >> b;
        vll v(a);
        for (int i = 0; i < a; ++i) {
            cin >> v[i];
        }
        int l = 0;
        int r = v.size() - 1;
        ll ans = 0;
        while (b > 0) {
            ll temp = min(v[l], v[r]);

            if (b >= temp * 2) {
                v[l] -= temp;
                v[r] -= temp;
                b -= temp * 2;
            } else if (b == 1) {
                v[l]--;
                b--;
            } else if (b >= temp) {
                v[l] -= temp / 2;
                v[r] -= temp / 2;
                b -= temp;
            }

            if (v[l] == 0) {
                ans++;
                l++;
            }
            if (v[r] == 0) {
                ans++;
                r--;
            }
            if (l > r) break;
            if (l == r) {
                if (b >= v[l] && v[l] != 0) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
