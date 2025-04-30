#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

ll init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

}

ll sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    else if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, m, k;
    cin >> n >> m >> k;
    vll v(n);
    vll tree(n * 4);
    for (ll &i: v) cin >> i;
    init(v, tree, 1, 0, n - 1);
    for (int i = 0; i < m + k; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(tree, 1, 0, n - 1, b - 1, c - v[b - 1]);
            v[b - 1] = c;
        } else {
            cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}
