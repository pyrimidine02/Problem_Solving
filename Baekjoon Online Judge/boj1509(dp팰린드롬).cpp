#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

bool ispalin[2501][2501];
int dp[2501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= s.size(); ++i) {
        ispalin[i][i] = true;
        if (i != 1 && s[i-1] == s[i]) ispalin[i-1][i] = true;
    }

    for (int i = 2; i < s.size() - 1; ++i) {
        for (int j = 0; i + j < s.size(); ++j) {
            if (ispalin[j + 2][i + j] && s[j+1] == s[i + j + 1]) ispalin[j + 1][i + j + 1] = true;
        }
    }

    for (int i = 1; i <= s.size(); ++i) {
        dp[i] = dp[i - 1] + 1;
        if (ispalin[1][i]) dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (ispalin[j+1][i]) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[s.size()] - 1;

    return 0;
}
