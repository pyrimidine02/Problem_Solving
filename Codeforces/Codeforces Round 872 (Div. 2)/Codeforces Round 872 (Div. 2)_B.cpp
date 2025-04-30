#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi p(n * m);
        for (int i = 0; i < n * m; ++i) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());
        if (n < m) swap(n, m);
        int result = max((p[p.size() - 1] - p[0]) * (n - 1) * m + (p[p.size() - 1] - p[1]) * (m - 1),
                         (p[p.size() - 1] - p[0]) * (n - 1) * m + (p[p.size() - 2] - p[0]) * (m - 1));

        cout << result << "\n";
    }
    return 0;
}