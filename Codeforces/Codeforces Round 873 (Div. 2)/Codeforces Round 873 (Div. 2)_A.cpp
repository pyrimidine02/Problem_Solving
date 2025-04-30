#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        for (int i = 1; i <= a; ++i) {
            p.push_back(2 * i);
        }
        for (int i = 0; i < a; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
        p.clear();
    }

    return 0;
}