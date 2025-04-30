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

int t;
int cnt = 0;
int check[26];

void dfs(int ans, int idx) {
    if (idx == t) {
        if (ans == (1 << 26) - 1) cnt++;
        return;
    }
    dfs(ans, idx + 1);
    dfs(ans | check[idx], idx + 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        int a = 0;
        for (int j = 0; j < s.size(); ++j) {
            a |= (1 << (s[j] - 'a'));
        }
        check[i] = a;
    }
    dfs(0, 0);
    cout << cnt << "\n";

    return 0;
}
