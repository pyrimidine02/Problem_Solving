#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> p[10001];
bool check[10001];
int mp, md = -1;

void dfs(int po, int d) {
    if (check[po]) return;

    check[po] = true;

    if (md < d) {
        md = d;
        mp = po;
    }

    for (int i = 0; i < p[po].size(); ++i) {
        int nextposition = p[po][i].first;
        int nextdist = p[po][i].second;
        dfs(nextposition, d + nextdist);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;
    for (int i = 0; i < v - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back({b, c});
        p[b].push_back({a, c});
    }


    dfs(1, 0);
    memset(check, false, sizeof(check));
    md = 0;
    dfs(mp, 0);
    cout << md << "\n";


    return 0;
}
