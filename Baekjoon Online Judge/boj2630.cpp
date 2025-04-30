#include <iostream>
#include <vector>

using namespace std;

int white, blue{0};
vector<vector<int>> x(129);
vector<int> y(129);

void check(int a, int b, int len) {
    int color = x[a][b];

    for (int i = a; i < a + len; i++) {
        for (int j = b; j < b + len; j++) {
            if (color != x[i][j]) {
                check(a, b, len / 2);
                check(a, b + len / 2, len / 2);
                check(a + len / 2, b, len / 2);
                check(a + len / 2, b + len / 2, len / 2);
                return;
            }
        }
    }
    if (color == 1) blue++;
    else white++;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;


    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            x[i].push_back(b);
        }
    }

    check(0, 0, a);

    cout << white << "\n" << blue;


    return 0;
}





