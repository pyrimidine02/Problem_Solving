#include <bits/stdc++.h>

using namespace std;
int p[101][101];
string aa[101];

int px[4] = {-1, 1, 0, 0};
int py[4] = {0, 0, 1, -1};
int pmove[101][101] = {};
bool check[101][101];
int n, m;

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        check[x][y] = true;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + px[i];
            int ny = y + py[i];
            if (p[nx][ny] == 0 || nx < 0 || ny < 0 || nx >= m || ny >= n || check[nx][ny]) continue;
            check[nx][ny] = true;
            q.push({nx, ny});
            if (pmove[nx][ny] == 0) pmove[nx][ny] = pmove[x][y] + 1;
            else { pmove[nx][ny] > pmove[x][y] + 1 ? pmove[nx][ny] = pmove[x][y] + 1 : pmove[nx][ny]; }
        }
    }
    cout << pmove[m-1][n-1] + 1<< "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char a = aa[i].at(j);
            p[j][i] = a - '0';
        }
    }
    bfs();


    return 0;
}