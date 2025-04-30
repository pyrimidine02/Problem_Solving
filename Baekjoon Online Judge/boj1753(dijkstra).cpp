#include <bits/stdc++.h>

#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int, int>> p[20001];
int dis[20001];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        int cur_dis = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (dis[cur] < cur_dis) continue;
        for (int i = 0; i < p[cur].size(); i++) {
            int next = p[cur][i].first;
            int next_dis = cur_dis + p[cur][i].second;
            if (dis[next] > next_dis) {
                dis[next] = next_dis;
                q.push(make_pair(next_dis, next));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, e, k;
    cin >> V >> e >> k;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        p[u].push_back(make_pair(v, w));

    }
    fill(dis, dis + 20001, INF);

    dijkstra(k);
    for (int i = 1; i <= V; i++) {
        if (dis[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dis[i] << endl;
        }
    }

    return 0;
}
