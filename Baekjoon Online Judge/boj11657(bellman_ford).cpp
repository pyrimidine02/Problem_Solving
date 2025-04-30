#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
typedef long long ll;
using namespace std;
vector<pair<int, int>> p[501];
ll dist[501];
int n, m;

void bellman_ford(int v) {
    bool cycle = false;
    fill(dist, dist + 501, INF);
    dist[v] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < p[j].size(); ++k) {
                int next = p[j][k].first;
                int next_d = p[j][k].second;
                if (dist[j] != INF && dist[next] > dist[j] + next_d) {
                    dist[next] = dist[j] + next_d;
                    if (i == n) cycle = true;
                }

            }
        }

    }
    if (cycle) cout << "-1\n";
    else {
        for (int i = 2; i <= n; ++i) {
            cout << (dist[i] != INF ? dist[i] : -1) << "\n";

        }
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back({b, c});

    }
    bellman_ford(1);


    return 0;
}