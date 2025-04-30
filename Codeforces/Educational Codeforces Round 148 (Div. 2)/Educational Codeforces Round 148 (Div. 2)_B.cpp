#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll mi = 1e18;
        ll sum = 0;
        ll n, k;
        vll f;
        vll e;
        cin >> n >> k;
        vll v(n);
        ll re;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        ll p = 0;
        f.push_back(0);
        e.push_back(0);
        for (ll i = 0; i < n; i += 2) {
            p += v[i] + v[i + 1];
            f.push_back(p);
        }
        p = 0;
        for (ll i = n-1; i >=0; i--) {
            p += v[i];
            e.push_back(p);
        }

        for (ll i = 0; i <= k; ++i) {
            re = f[i] + e[k-i];
            if (re < mi) mi = re;
        }

        for (ll i = 0; i < v.size(); ++i) {
            sum += v[i];
        }

        cout << sum - mi << "\n";
        v.clear();
        f.clear();
        e.clear();
    }

    return 0;
}