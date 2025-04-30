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
        vi v(a);
        for (auto &i: v) {
            cin >> i;
        }
        bool flag = false;
        sort(v.begin(), v.end());
        int t1 = v[0], t2 = v[1];
        bool tt = false;
        for (auto i: v) {
            if (i % t1 != 0 && !tt) {
                t2 = i;
                tt = true;
            }
            else if (i % t1 != 0 && i % t2 != 0) {
                flag = true;
                break;
            }
        }
        if (flag)cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}