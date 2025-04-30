#include <bits/stdc++.h>

using namespace std;
vector<bool>prime(10000000);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        prime[i] = true;
    }

    prime[0] = 0;
    prime[1] = 0;

    for (int k = 2; k <= n; k++) {
        if (prime[k]) {
            for (int h = k * 2; h <= n; h = h + k) {
                prime[h] = false;
            }
        }

        if (prime[k] == 0) {
            continue;
        }
    }
    for (int j = m; j <= n; j++) {
        if (prime[j]) {
            cout << j << "\n";
        }
    }
    return 0;
}