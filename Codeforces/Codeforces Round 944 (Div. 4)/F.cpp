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
        ll ans = 4;
        int a;
        cin >> a;
        ll temp = 0;
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= a; ++j) {
                ll aa = (i * i) + (j * j);
                if (aa >= a * a && aa < (a + 1) * (a + 1))temp++;
                if (aa >= (a + 1) * (a + 1))break;
            }
        }
        ans += temp * 4;
        cout << ans << "\n";
    }

    return 0;
}
