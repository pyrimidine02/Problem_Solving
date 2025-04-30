#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;
int pos[1001][1001]{};
bool check[1001][1001];
int movex[4]{0, 0, -1, 1};
int movey[4]{-1, 1, 0, 0};
int n, m, l, r;
int xf, yf;
int cnt = 0;
string aa[1001];
int rr[1001][1001] {}, ll[1001][1001] {};

void bfs() {
    deque<pair<int, int>> dq;

    dq.push_front({xf, yf});
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        check[x][y] = true;
        dq.pop_front();
        for (int i = 0; i < 4; ++i) {
            int px = x + movex[i];
            int py = y + movey[i];
            if (pos[px][py] == 1 || px < 0 || py < 0 || px >= m || py >= n || check[px][py]) continue;

            if (i == 0 || i == 1) {
                dq.push_front({px, py});
                cnt++;
                rr[px][py] = rr[x][y];
                ll[px][py] = ll[x][y];
                check[px][py] = true;
            } if (i == 2 && ll[x][y] <l) {
                dq.push_back({px, py});
                cnt++;
                ll[px][py] = ll[x][y] + 1;
                rr[px][py] = rr[x][y];
                check[px][py] = true;
            } if (i == 3 && rr[x][y] < r) {
                dq.push_back({px, py});
                cnt++;
                rr[px][py] = rr[x][y] + 1;
                ll[px][py] = ll[x][y];
                check[px][py] = true;
            }
//            cout << px << " " << py << " " << cnt << "\n";
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> l >> r;
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char a = aa[i].at(j);
            pos[j][i] = a - '0';
            if (a == '2') {
                xf = j;
                yf = i;
            }
        }
    }

    bfs();
    cout << cnt + 1 << "\n";


//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//           cout << check[j][i] << " ";
//
//        } cout << "\n";
//    }cout << "\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << ll[j][i] << " ";
//
//        } cout << "\n";
//    }
//    cout << "\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << rr[j][i] << " ";
//
//        } cout << "\n";
//    }


    return 0;
}
