#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> p[100001];
bool check[100001];
int mp, md;

void dfs(int po, int d) {

    if (check[po]) return;

    if (md < d) {
        md = d;
        mp = po;
    }
    check[po] = true;

    for (int i = 0; i < p[po].size(); ++i) {
        int nextposition = p[po][i].first;
        int nextdist = p[po][i].second;
        dfs(nextposition, nextdist + d);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v;
    cin >> v;
    for (int i = 0; i < v; ++i) {
        int a;
        cin >> a;
        int b, c;
        while (1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            p[a].push_back({b, c}); // p , d
        }
    }

    dfs(1, 0);
    memset(check, false, sizeof(check));
    md = 0;
    dfs(mp, 0);
    cout << md << "\n";


    return 0;
}
