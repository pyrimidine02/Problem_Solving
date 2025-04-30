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

int dfs_cnt = 0;
int m[500001];
vi edge[500001];
pii ett[500001];
ll segTree[2000004];
ll lazy[2000004];
vector<pll> arr;

void dfs(int c, int p) {
    arr.push_back({c, m[c]});
    dfs_cnt++;
    ett[c].first = dfs_cnt;
    for (int i = 0; i < edge[c].size(); ++i) {
        int next = edge[c][i];
        if (next == p) continue;
        dfs(next, c);
    }
    ett[c].second = dfs_cnt;
}

void setLazy(int ptr, int l, int r) {
    ll temp = lazy[ptr];
    lazy[ptr] = 0;
    segTree[ptr] += (r - l + 1) * temp;
    if (l != r) {
        lazy[ptr * 2] += temp;
        lazy[ptr * 2 + 1] += temp;
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

    int a, b;
    cin >> a >> b;
    cin >> m[1];
    for (int i = 2; i <= a; ++i) {
        cin >> m[i];
        int c;
        cin >> c;
        edge[c].push_back(i);
    }
    dfs(1, 0);

    for (int i = 1; i <= a; i++) {
        update(1, 1, a, ett[i].first, ett[i].first, m[i]);
    }
    while (b--) {
        string s;
        cin >> s;
        if (s == "p") {
            int x, y;
            cin >> x >> y;
            update(1, 1, a, ett[x].first + 1, ett[x].second, y);
        } else {
            int x;
            cin >> x;
            cout << getVal(1, 1, a, ett[x].first, ett[x].first) << '\n';
        }
    }
    return 0;
}
