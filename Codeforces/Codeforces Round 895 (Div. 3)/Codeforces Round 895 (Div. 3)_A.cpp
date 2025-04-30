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
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        if (a < b) swap(a, b);
        int cnt = 0;
        while (1) {
            a -= c;
            b += c;
            cnt++;
            if (b >= a)break;
        }
        cout << cnt << "\n";
    }


    return 0;
}