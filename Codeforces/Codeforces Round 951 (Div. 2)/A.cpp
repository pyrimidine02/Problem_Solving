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
        vi aa;
        for (int i = 0; i < v.size() - 1; ++i) {
            aa.push_back(max(v[i], v[i + 1]));
        }
        sort(aa.begin() , aa.end());
        cout << aa[0] - 1 << "\n";

    }

    return 0;
}
