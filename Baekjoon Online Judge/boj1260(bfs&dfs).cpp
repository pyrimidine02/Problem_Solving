#include <bits/stdc++.h>
using namespace std;

vector<int> p[1001];
vector<bool> check(1001);
vector<bool> check2(1001);


void bfs(int a) {
    queue<int> q;
    q.push(a);
    check2[a] = 1;
    while (!q.empty()) {
        int c = q.front();
        cout << c << " ";
        q.pop();
        for (int i = 0; i < p[c].size(); i++) {
            int next = p[c][i];
            if (check2[next] == 0) {
                q.push(next);
                check2[next] = 1;
            }
        }
    }
}

void dfs(int a) {
    check[a] = 1;
    cout << a << " ";
    for (int i = 0; i < p[a].size(); i++) {
        int next = p[a][i];
        if (check[next] == 0) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(p[i].begin(), p[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);

}



