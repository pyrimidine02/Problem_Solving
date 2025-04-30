#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, a, b, c;
vector<pair<int, int>> p[1001];
int dist[1001];
int path[1001];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int cd = pq.top().first;
        int c = pq.top().second;
        pq.pop();
        if (dist[c] < cd) continue;
        for (int i = 0; i < p[c].size(); i++) {
            int next = p[c][i].first;
            int nd = cd + p[c][i].second;
            if (dist[next] > nd) {
                dist[next] = nd;
                pq.push(make_pair(nd, next));
                path[next] = c;
            }

        }

    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        p[a].push_back({b, c});
    }
    fill(dist, dist + 1001, INF);
    int d, e;
    cin >> d >> e;
    dijkstra(d);
    cout << dist[e] << "\n";
    int cc = 0;
    stack<int> ppp;
    int sss = e;
    ppp.push(sss);
    while (cc != d) {
        cc = path[sss];
        ppp.push(cc);
        sss = cc;
    }
    cout << ppp.size() << "\n";
    while (!ppp.empty()) {
        int ou = ppp.top();
        ppp.pop();
        cout << ou << " ";
    }

    return 0;
}