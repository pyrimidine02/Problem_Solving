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

    ll n, m;
    cin >> n >> m;
    vi v(n + 1);
    vi c(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
    }
    for (int i = m - 1; i >= 1; --i) {
        c[i] = min(c[i], c[i + 1]);
    }
    vll dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + c[1];
        for (int j = i - 1; j >= 0; --j) {
            if(v[i] - v[j] + 1 > m) break;
            dp[i] = min(dp[i], dp[j] + c[v[i] - v[j+1] + 1]);
        }
    }

    cout << dp[n];

    return 0;
}
