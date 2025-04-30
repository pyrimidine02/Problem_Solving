#include <iostream>
#include <queue>

using namespace std;

int tp[1002][1002];
bool vs[1002][1002];
int day[1002][1002]{0};
int movex[4]{0, 0, -1, 1};
int movey[4]{-1, 1, 0, 0};
int a, b;
int Max;
struct pos {
    int x, y;
};
queue<pos> p;

int bfs(int a, int b) {


    while (!p.empty()) {
        int x = p.front().x;
        int y = p.front().y;
        p.pop();


        for (int k = 0; k < 4; k++) {
            int px = x + movex[k];
            int py = y + movey[k];


            if (px < 0 || py < 0 || px >= a || py >= b || tp[px][py] == -1 || vs[px][py] == 1) {
                continue;
            } else if (tp[px][py] == 0 && vs[px][py] == 0) {
                p.push({px, py});
                vs[px][py] = 1;
                day[px][py] = day[x][y] + 1;
                tp[px][py] = 1;

            }
        }
    }
    Max = day[0][0];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {

            if (Max < day[i][j]) {
                Max = day[i][j];
            }
            if (vs[i][j] == 0 && tp[i][j] == 0) {
                return -1;
            }
        }
    }


    return Max;
}


int main() {
    int P{0}, Q{0};
    cin >> b >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> tp[i][j];

            if (tp[i][j] == 1) {
                P = P + 1;
                p.push({i, j});
                vs[i][j] = 1;
            }
            if (tp[i][j] == -1) {
                Q = Q + 1;
            }
        }
    }

    if (P + Q == a * b) {
        cout << "0";
        return 0;
    }


    int result = bfs(a, b);


    cout << result;
    return 0;
}

