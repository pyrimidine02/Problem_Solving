#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> p[801];
int p1, p2;
int len[801];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(len, len+801, INF);
    len[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int current = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (len[current] < dist) continue;
        for (int i = 0; i<p[current].size(); i++) {
            int next = p[current][i].first;
            int next_dist = dist + p[current][i].second;
            if (next_dist < len[next]) {
                len[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back({b, c});
        p[b].push_back({a, c});
    }
    cin >> p1 >> p2;
    dijkstra(1);
    int d1 = len[p1];
    int d2 = len[p2];

    dijkstra(p1);
    int d1p2 = len[p2];
    int d1n = len[n];

    dijkstra(p2);
    int d2n = len[n];

    if(d1 == INF || d2 == INF ||d1p2 == INF || d1n == INF || d2n == INF){
        cout << "-1\n";
        return 0;
    }

    int ans = min(d1+d1p2+d2n, d2+d1p2+d1n);
    cout << ans << "\n";
    return 0;
}
