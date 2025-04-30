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
priority_queue<pii> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a == 0) {
            if (pq.size() == 0) cout << 0 << "\n";
            else {
                cout << -pq.top().second << "\n";
                pq.pop();
            }
        } else
            pq.push({-abs(a), -a});
    }

    return 0;
}

