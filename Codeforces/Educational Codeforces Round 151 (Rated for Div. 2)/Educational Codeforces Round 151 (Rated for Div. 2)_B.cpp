#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a3, b1, b2, b3;
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
        int dx2 = a2 - a1;
        int dy2 = b2 - b1;
        int dx3 = a3 - a1;
        int dy3 = b3 - b1;
        int ans = 0;
        if ((dx2 > 0 && dx3 > 0) || (dx2 < 0 && dx3 < 0)) {
            ans = ans + min(abs(dx2), abs(dx3));
        }
        if ((dy2 > 0 && dy3 > 0) || (dy2 < 0 && dy3 < 0)) {
            ans = ans + min(abs(dy2), abs(dy3));
        }
        cout << ans + 1 << "\n";

    }


    return 0;
}