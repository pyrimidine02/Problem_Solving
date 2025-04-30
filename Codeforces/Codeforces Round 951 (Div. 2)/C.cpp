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
        int n;
        cin >> n;
        vi v(n);
        for (auto &i: v) {
            cin >> i;
        }
        ll temp = 1;
        for (auto i: v) {
            temp = lcm(temp, i);
        }
        vi ans;
        ll temp2 = 0;
        for (auto i: v) {
            ans.push_back(temp / i);
            temp2 += (temp / i);
        }
        if (temp2 >= temp) {
            cout << "-1\n";
        } else {
            for (auto &i: ans) {
                cout << i << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
