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
        int n, c, d;
        cin >> n >> c >> d;
        vi v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int a;
                cin >> a;
                v.push_back(a);
            }
        }
        sort(v.begin(), v.end());
        int s = v[0];
        vi ans;
        for (int i = 0; i < n; ++i) {
            int temp = s;
            for (int j = 0; j < n; ++j) {
                ans.push_back(temp);
                temp += d;
            }
            s += c;
        }
        sort(ans.begin(), ans.end());
        if (v == ans) {
            cout << "YES\n";
        } else cout << "NO\n";
    }


    return 0;
}
