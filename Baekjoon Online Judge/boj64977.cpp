#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
int parent[200001];
int n, m;


struct node_mst {
    int cost;
    int from;
    int to;
};
vector<node_mst> v;

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

bool comp(node_mst n1, node_mst n2) {
    return n1.cost < n2.cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        ll result = 0;
        ll sum = 0;
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        v.clear();
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({c, a, b});
            sum += c;
        }

        for (int i = 0; i <= m; i++) parent[i] = i;

        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < v.size(); i++) {
            if (!sameparent(v[i].from, v[i].to)) {
                merge(v[i].from, v[i].to);
                result += v[i].cost;
            }
        }
        cout << sum - result << "\n";
    }

    return 0;
}
