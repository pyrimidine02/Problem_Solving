#include <bits/stdc++.h>

#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int, int>> p[100002];
int d[100002];


void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        int c_d = q.top().first;
        int c = q.top().second;
        q.pop();
        if (d[c] < c_d) continue;
        for (int i = 0; i < p[c].size(); i++) {
            int next = p[c][i].first;
            int nd = c_d + p[c][i].second;
            if (d[next] > nd) {
                d[next] = nd;
                q.push(make_pair(nd, next));

            }

        }


    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p[0].push_back(make_pair(1,1));
    for (int i = 1; i <= 50000; i++) {
        p[i].push_back(make_pair(i - 1, 1));
        p[i].push_back(make_pair(i + 1, 1));
        p[i].push_back(make_pair(2 * i, 1));
    }
    for(int i = 50001; i <=100000; i++){
        p[i].push_back(make_pair(i - 1, 1));
        p[i].push_back(make_pair(i + 1, 1));
    }
    fill(d, d + 100002, INF);
    int a, b;
    cin >> a >> b;

    dijkstra(a);

    cout << d[b] << endl;


    return 0;
}
