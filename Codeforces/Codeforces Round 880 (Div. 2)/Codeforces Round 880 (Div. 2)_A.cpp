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

int c[200];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(c, 0, sizeof(c));
        int max = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            c[a]++;
            if(max < a) max =a;
        }
        int m = 0;
        for (int i = 0; i < max; ++i) {
            if(c[i]<c[i+1]) {
                cout << "NO\n";
                break;
            }
            if(c[i] == 0) {
                cout << "NO\n";
                break;
            }
            m++;
        }
        if(m == max) cout << "YES\n";

    }
    return 0;
}