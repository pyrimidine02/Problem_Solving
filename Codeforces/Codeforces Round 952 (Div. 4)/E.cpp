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

ll gcd(ll a, ll b) {
    for (; b; a %= b, swap(a, b));
    return a;
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int MOD = 1e9 + 7;

int dp[20][200][2];


int fun1(int a, int b, int c, vector<int> &d) {
    if (a == d.size()) {
        return b;
    }

    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }

    int limit = (c) ? d[a] : 9;
    int res = 0;

    for (int e = 0; e <= limit; e++) {
        res = (res + fun1(a + 1, b + e, c && (e == d[a]), d)) % MOD;
    }

    return dp[a][b][c] = res;
}


int fun2(long long x) {
    vector<int> d;
    while (x > 0) {
        d.push_back(x % 10);
        x /= 10;
    }

    reverse(d.begin(), d.end());

    memset(dp, -1, sizeof(dp));
    return fun1(0, 0, 1, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> tests(n);

    for (int f = 0; f < n; ++f) {
        ll g, h, i;
        cin >> g >> h >> i;
        tests[f] = make_tuple(g, h, i);
    }

    for (auto &test: tests) {
        ll g = get<0>(test);
        ll h = get<1>(test);
        ll i = get<2>(test);

        ll j = 0;

        for (ll k = g; k <= h; ++k) {
            ll sum_k = fun2(k);
            ll sum_ik = fun2(k * i);

            if (sum_ik == sum_k * i) {
                j = (j + 1) % MOD;
            }
        }

        cout << j << '\n';
    }

    return 0;
}