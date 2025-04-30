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
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << "\n";
        } else if (k == 1) {
            cout << "NO\n";
        } else if (n % 2 == 0) {
            cout << "YES\n";
            cout << n / 2 << "\n";
            for (int i = 0; i < n / 2; ++i) {
                cout << 2 << " ";
            }
            cout << "\n";
        } else if (n % 2 == 1 && k < 3) {
            cout << "NO\n";
        } else if (n % 2 == 1 && k > 2) {
            cout << "YES\n";
            int a = n / 3;
            int b = n % 3;
            if (b == 2) {
                cout << a + 1 << "\n";
                for (int i = 0; i < a; ++i) {
                    cout << 3 << " ";
                }
                cout << 2 << "\n";
            } else if (b == 1) {
                cout << a + 1 << "\n";
                for (int i = 0; i < a - 1; ++i) {
                    cout << 3 << " ";
                }
                cout << 2 << " " << 2 << "\n";
            } else {
                cout << a << "\n";
                for (int i = 0; i < a; ++i) {
                    cout << 3 << " ";
                }
                cout << "\n";
            }
        }
    }


    return 0;
}