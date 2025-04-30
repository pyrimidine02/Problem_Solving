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
        int a;
        cin >> a;
        vll v(a);
        for (auto &i: v) {
            cin >> i;
        }
        if (a == 2) cout << min(v[0], v[1]) << "\n";
        else {
            ll m = -1;
            for (int i = 0; i < v.size() - 2; ++i) {
                vll v1(v.begin() + i, v.begin() + i + 3);
                sort(v1.begin(), v1.end());
                m = max(m, v1[1]);
            }
            cout << m << "\n";
        }


    }

    return 0;
}
