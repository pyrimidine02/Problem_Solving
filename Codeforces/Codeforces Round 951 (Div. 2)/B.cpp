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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int temp = 0;
        char cmp = 'a';
        bool flag = false;
        bool flag1 = false;
        bool flag2 = false;
        int cnt = 0;
        int idx = 0;
        int idx2 = 0;
        int cnt2 = 0;
        for (int i = 0; i < a; ++i) {
            if (temp == 0 && cmp != s[i]) {
                cmp = s[i];
                temp++;
            } else if (cmp == s[i] && temp != 0) {
                temp++;
            }
            if ((cmp != s[i] || (temp == 0 && cmp == s[i])) && flag && !flag2) {
                flag1 = true;
                break;
            }
            if ((cmp != s[i] || (temp == 0 && cmp == s[i])) && flag && flag2) {
                idx2 = i - b;
                cnt2 = b - temp;
                cmp = s[i];
                temp = 1;
            }
            if ((cmp != s[i] || (temp == 0 && cmp == s[i])) && !flag) {
                flag = true;
                cmp = s[i];
                cnt = temp;
                if (temp == 0) cnt = 1;
                if ((temp == 0 && cmp == s[i])) {
                    flag2 = true;
                }
                temp = 1;
                idx = i;
            }

            if (temp == b) {
                temp = 0;
                flag2 = false;
            }
        }
        if (idx == 0) idx = a;
        bool c = false;
        if (!flag1) {
            if ((cnt + temp) % b == 0 && s[idx - 1] == s[a - 1] && cnt2 == 0) {
                cout << idx << "\n";
            } else if (temp == 0 && cnt == b) cout << idx << "\n";
            else if (idx2 != 0) {
                if ((cnt2 + temp) % b == 0 && s[idx2 - 1] == s[a - 1]) {
                    cout << idx2 << "\n";
                }else {
                    c = true;
                }
            } else {
                c = true;
            }
        }else{
            cout << "-1\n";
        }
        if (c) cout << "-1\n";
    }


    return 0;
}
