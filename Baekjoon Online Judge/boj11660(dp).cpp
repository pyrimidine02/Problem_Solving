#include <iostream>
using namespace std;

int p[1025][1025];
int s[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> p[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + p[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;

        int re = s[xx][yy] - s[xx][y-1] - s[x-1][yy] + s[x-1][y-1];
        cout << re << "\n";
    }

    return 0;
}
