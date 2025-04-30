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


int fun(int r) {
    int count = 0;
    for (int x = -r; x <= r; ++x) {
        for (int y = -r; y <= r; ++y) {
            if (x * x + y * y <= r * r) {
                count++;
            }
        }
    }
    return count;
}

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
        ll n, k, q;
        cin >> n >> k >> q;
        vll v1(k + 1);
        for (int i = 1; i <= k; ++i) {
            cin >> v1[i];
        }
        vll v2(k + 1);
        for (int i = 1; i <= k; ++i) {
            cin >> v2[i];
        }
        while (q--) {
            ll a;
            cin >> a;
            ll ans = 0;
            ll temp = 0;
            bool flag = false;
            for (int i = 0; i < v1.size(); ++i) {
                if (v1[i] == a) {
                    cout << v2[i] << " ";
                    flag = true;
                    break;
                }
                if (v1[i] > a) {
                    ans += v2[i - 1];
                    temp = i;
                    break;
                }
            }
            if (flag) continue;
            long double cal = 0;
            cal = (long double)(v2[temp] - v2[temp - 1]) / (v1[temp] - v1[temp - 1]);
            cal = cal * (a - v1[temp - 1]);
            ans += floor(cal);
            cout << ans << " ";
        }
        cout << "\n";


    }

    return 0;
}
