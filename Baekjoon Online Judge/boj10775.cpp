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

int parent[1000000];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) parent[i] = i;
    while (m--) {
        int a;
        cin >> a;
        a = find(a);
        if (a == 0) break;
        else merge(a - 1, a);
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
