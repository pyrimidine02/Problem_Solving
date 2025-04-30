#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int parent[100001];
int dist[100001];

int find(int x) {
    if (x == parent[x]) return x;
    int par = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = par;
}

void merge(int x, int y, int w) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    dist[py] = dist[x] - dist[y] + w;
    parent[py] = px;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    while (1) {
        for (int i = 0; i < 100001; ++i) {
            parent[i] = i;
        }
        memset(dist, 0, sizeof(dist));
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        for (int i = 0; i < b; ++i) {
            string s;
            cin >> s;
            if (s == "!") {
                int n, m, d;
                cin >> n >> m >> d;
                merge(n, m, d);

            } else {
                int n, m;
                cin >> n >> m;
                if (find(n) != find(m)) cout << "UNKNOWN\n";
                else cout << (dist[m] - dist[n]) << "\n";
            }
        }
    }

    return 0;
}

