#include <bits/stdc++.h>

using namespace std;
queue<pair<int, int>> q;
bool check[100001];
int n, m, cnt = 0;
int ans;

void bfs(int n, int t) {
    q.push({n, t});
    while (!q.empty()) {
        int n = q.front().first;
        int t = q.front().second;
        q.pop();
        check[n] = true;
        if (n == m) {
            if (cnt == 0) {
                ans = t;
                cnt++;
            } else if (cnt > 0 && ans == t)
                cnt++;
        }
        int move[3] = {n - 1, n + 1, 2 * n};
        for (int i = 0; i < 3; i++) {
            int next = move[i];
            if (0 <= next && next <= 100000 && !check[next]) {
                q.push({next, t + 1});
            }
        }
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    if (n == m) {
        cout << '0' << '\n' << '1';
    } else {
        bfs(n, 0);
        cout << ans << '\n' << cnt;
    }
    return 0;
}