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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vi v[30];
    vi c(30);
    for (int i = 0; i < s.size(); ++i) {
        v[s[i] - 'a'].push_back(i);
        c[s[i] - 'a']++;
    }
    for (auto c: t) {
        if (v[c - 'a'].empty()) {
            cout << "0\n";
            return 0;
        }
    }
    auto fun = [&](ll cycle, ll begin, char target, ll count) -> pll {
        vi &pos = v[target - 'a'];



    };
    ll left = 0, right = INF;
    while (left < right){






    }


    return 0;
}
