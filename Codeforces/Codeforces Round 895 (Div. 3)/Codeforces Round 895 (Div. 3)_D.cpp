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
        ll n, x, y;
        cin >> n >> x >> y;
        if (x == y) {
            cout << 0 << "\n";
            continue;
        }
        ll a = n / x - n / (x * y / gcd(x, y));
        ll b = n / y - n / (x * y / gcd(x, y));
        ll s1 = (2*n+1 -a)*a/2;
        ll s2 = b*(b+1)/2;

        cout << s1 - s2 << "\n";
    }


    return 0;
}