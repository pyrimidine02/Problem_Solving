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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s == "I") {
                int a;
                cin >> a;
                ms.insert(a);
            } else {
                int a;
                cin >> a;
                if (ms.empty()) continue;
                else if (a == 1) {
                    auto itr = ms.end();
                    itr--;
                    ms.erase(itr);
                } else {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.size() == 0) cout << "EMPTY\n";
        else {
            auto itr = ms.end();
            itr--;
            cout << *itr << " " << *ms.begin() << "\n";
        }
    }


    return 0;
}
