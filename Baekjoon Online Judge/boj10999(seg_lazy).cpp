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


ll segTree[4000004];
ll lazy[4000004];

void setLazy(int ptr, int l, int r) {
    ll val = lazy[ptr];
    lazy[ptr] = 0;
    segTree[ptr] += (r - l + 1) * val;

    if (l != r) {
        lazy[ptr * 2] += val;
        lazy[ptr * 2 + 1] += val;
    }

}

void update(int ptr, int l, int r, int i, int j, ll val) {
    if (lazy[ptr]) setLazy(ptr, l, r);

    if (j < l || r < i) return;
    if (i <= l && r <= j) {
        segTree[ptr] += (r - l + 1) * val;

        if (l != r) {
            lazy[ptr * 2] += val;
            lazy[ptr * 2 + 1] += val;
        }
        return;
    }
    update(ptr * 2, l, (l + r) / 2, i, j, val);
    update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j, val);

    segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(int ptr, int l, int r, int i, int j) {
    if (lazy[ptr]) setLazy(ptr, l, r);
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
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        ll x;
        cin >> x;
        update(1, 1, a, i, i, x);
    }

    b += c;
    while (b--) {
        int q;
        cin >> q;
        if (q == 1) {
            ll i, j, k;
            cin >> i >> j >> k;
            update(1, 1, a, i, j, k);

        } else {
            ll x, y;
            cin >> x >> y;
            cout << getVal(1, 1, a, x, y) << '\n';
        }
    }

    return 0;
}
