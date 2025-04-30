#include <bits/stdc++.h>

using namespace std;
const int INF = (int) 1e12;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


int dp[101][10][1024];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i < 10; ++i) {
        dp[1][i][(1 << i)] = 1;
    }
    for (int i = 2; i <= n; ++i) { // n열
        for (int j = 0; j < 10; ++j) {  // 마지막 번호
            for (int bit = 0; bit < (1 << 10); ++bit) {
                if (j == 0) {
                    dp[i][j][bit | 1 << j] += dp[i - 1][j + 1][bit] % (int)10e8;
                } else if (j == 9) {
                    dp[i][j][bit | 1 << j] += dp[i - 1][j - 1][bit] % (int)10e8;
                } else {
                    dp[i][j][bit | 1 << j] += dp[i - 1][j - 1][bit]  % (int)10e8;
                    dp[i][j][bit | 1 << j] +=  dp[i - 1][j + 1][bit] % (int)10e8;
                }
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[n][i][1023] % (int)10e8;
    }
    cout << sum % (int)10e8;

    return 0;

}
