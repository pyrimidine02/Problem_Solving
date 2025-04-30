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
        bool check = false;
        bool flag = false;
        int start = v[0];
        int temp;
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] > v[i + 1] && !check) {
                check = true;
            } else if (v[i] > v[i + 1] && check) {
                flag = true;
                break;
            }
        }
        if (check) if (v[v.size() - 1] > v[0]) flag = true;
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}
