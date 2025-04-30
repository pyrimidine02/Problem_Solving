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
    int n, m, k;
    cin >> n >> m >> k;
    multiset<char> ms[k + 1][k + 1];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            ms[j % k + 1][i % k + 1].insert(s[j]);
        }
    }
    int max;
    int rst = 0;
    char p[k + 1][k + 1];
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            max = 0;
            for (char l = 'A'; l <= 'Z'; l++) {
                int cnt = ms[j][i].count(l);
                if (cnt > max) {
                    max = cnt;
                    p[j][i] = l;
                }
            }
            rst += (m / k) * (n / k) - max;
        }
    }

    cout << rst << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << p[j % k + 1][i % k + 1];
        }
        cout << "\n";
    }


    return 0;
}