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

int n;
ll segTree[400004];

void update(int ptr, int l, int r, int i, ll val) {
    if (i < l || r < i) return;
    if (l == r) {
        segTree[ptr] += val;
        return;
    }

    update(ptr * 2, l, (l + r) / 2, i, val);
    update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

    segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(int ptr, int l, int r, int i, int j) {
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return segTree[ptr];

    return getVal(ptr * 2, l, (l + r) / 2, i, j)
           + getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> n;
    ll last = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        update(1, 1, n, i, a - last);
        last = a;
    }

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            ll i, j, k;
            cin >> i >> j >> k;
            update(1, 1, n, i, k);
            update(1, 1, n, j + 1, -k);
        } else {
            ll x;
            cin >> x;
            cout << getVal(1, 1, n, 1, x) << '\n';
        }
    }

    return 0;
}
