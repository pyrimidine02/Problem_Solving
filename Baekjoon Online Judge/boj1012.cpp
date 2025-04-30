#include <bits/stdc++.h>

using namespace std;

int p[51][51];
bool check[51][51];

int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, -1, 1};
int cnt;
int m, n, k;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    check[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int dx = cx + movex[i];
            int dy = cy + movey[i];
            if (dx < 0 || dy < 0 || dx > m || dy > n || check[dx][dy] == true || p[dx][dy] == 0) continue;
            check[dx][dy] = true;
            q.push({dx, dy});
        }
    }
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        cin >> m >> n >> k;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                p[i][j] = 0;
            }
        }
        cnt = 0;
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            p[a][b] = 1;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[i][j] == 1 && check[i][j] == false)
                    bfs(i, j);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
