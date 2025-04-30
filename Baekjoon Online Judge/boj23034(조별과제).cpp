#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
struct node_mst {
    int cost;
    int from;
    int to;
};

bool comp(node_mst n1, node_mst n2) {
    return n1.cost < n2.cost;
}

struct node_bfs {
    int to;
    ll dis;
};

vector<node_mst> v;
vector<node_bfs> p[1001];
int parent[1001];
bool check[1001];
ll dist[1001][1001];


int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return true;
    else return false;
}

void bfs(int s) {
    memset(check, 0, sizeof(check));
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < p[current].size(); ++i) {
            int next = p[current][i].to;
            ll cost = p[current][i].dis;
            if (!check[next]) {
                check[next] = true;
                dist[s][next] = max(dist[s][current], cost);
                q.push(next);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    long long result = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});

    }

    sort(v.begin(), v.end(), comp);

    int q;
    cin >> q;

    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].from, v[i].to)) {
            merge(v[i].from, v[i].to);
            p[v[i].from].push_back({v[i].to, v[i].cost});
            p[v[i].to].push_back({v[i].from, v[i].cost});


            result += v[i].cost;
        }
    }
    for (int i = 0; i < n; ++i) {
        bfs(i);
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = max(dist[a][b], dist[b][a]);
        cout << result - dist[a][b] << "\n";
    }

    return 0;
}
