#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size() / 2; ++i) {
            if (s1[i] - '0' < s2[i] - '0') {
                char temp = s1[i];
                s1[i] = s2[i];
                s2[i] = temp;
            }
        }
        for (int i = s1.size() / 2; i < s1.size(); ++i) {
            if (s1[i] - '0' > s2[i] - '0') {
                char temp = s1[i];
                s1[i] = s2[i];
                s2[i] = temp;
            }
        }
        cout << s1 << "\n" << s2 << "\n";

    }

    return 0;
}