#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
int length[501];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pii> v;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int result = 0;
    for (int k = 0; k < t; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (v[i].second < v[k].second) {
                length[k] = max(length[k], length[i] + 1);
            }
            result = max(result, length[k]);
        }

    }

    cout << t - result << "\n";


    return 0;
}
