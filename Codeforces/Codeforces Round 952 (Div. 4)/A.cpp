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
        string a, b;
        cin >> a >> b;
        cout << b[0] << a[1] << a[2] << " ";
        cout << a[0] << b[1] << b[2] << "\n";

    }

    return 0;
}