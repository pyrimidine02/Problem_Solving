#include <bits/stdc++.h>

using namespace std;
bool dp[2001][2001];
vector<int> num(2001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= t; ++i) {
        dp[i][i] = true;
        if (i != 1 && num[i - 1] == num[i]) dp[i - 1][i] = true;
    }

    for (int i = 2; i < t ; ++i) {
        for (int j = 1; i + j <= t ; ++j) {
            if(dp[j+1][i+j-1] && num[j] == num[i+j]) dp[j][i+j] = true;
        }
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int s,e;
        cin >> s >> e;
        if(dp[s][e]) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}
