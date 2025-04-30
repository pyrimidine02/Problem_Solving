#include <bits/stdc++.h>

using namespace std;

bool check[1001];
vector<int> p[1001];
int cnt = 0;

void bfs(int n) {
    queue<int> q;
    q.push(n);
    check[n] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < p[cur].size(); i++) {
            int next = p[cur][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (check[i] == false) bfs(i);
    }

    cout << cnt << '\n';

    return 0;
}
