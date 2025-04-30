#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<pair<int, int>> v[100001];
ll path[100001];
int n, m;

void dijkstra(int a) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(path, path + 100001, 1e12);
    path[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
        int cp = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        if (path[cp] < dist)continue;
        for (int i = 0; i < v[cp].size(); ++i) {
            int next = v[cp][i].first;
            ll next_dist = dist + v[cp][i].second;
            if (path[next] > next_dist) {
                path[next] = next_dist;
                pq.push({next_dist, next});
            }
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
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    int s, t;
    cin >> s >> t;
    dijkstra(s);
    cout << path[t] << "\n";
    return 0;
}
