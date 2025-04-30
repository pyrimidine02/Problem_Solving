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
        int a, b;
        cin >> a >> b;
        int x, y = 1;
        string c[a];
        for (int i = 0; i < a; ++i) {
            cin >> c[i];
        }
        bool flag = false;
        bool f2 = false;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < a; ++j) {
                if (c[j][i] == '#' && !flag) {
                    x = j + 1;
                    flag = true;
                }
                if (i != b - 1) {
                    if (c[j][i] == '#' && c[j][i + 1] == '.') {
                        y = i + 1;
                        f2 = true;
                    }
                }
                if(i == b-1){
                    if(!f2 && flag) {
                        y = b;
                        f2 = true;
                    }
                }
                if (f2) break;
            }
            if (f2)break;
        }
        cout << x << " " << y << "\n";


    }

    return 0;
}