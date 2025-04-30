#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v[300001];
bool p[100001];
long long path[300001];
int n, m;

void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(path, path + 300001, 1e12);
    path[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int cp = pq.top().second;
        long long dist = pq.top().first;
        pq.pop();
        if (path[cp] < dist)continue;
        for (int i = 0; i < v[cp].size(); ++i) {
            int next = v[cp][i].first;
            long long next_dist = dist + v[cp][i].second;
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
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (p[a] == 1 || p[b] == 1) {if (a != n - 1 && b != n - 1) continue;}
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra();
    if (path[n - 1] == 1e12) cout << "-1\n";
    else cout << path[n - 1] << "\n";

    return 0;
}
