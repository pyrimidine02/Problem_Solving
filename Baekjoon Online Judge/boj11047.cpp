#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;
int a[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += k / a[i];
        k = k % a[i];
    }

    cout << sum << '\n';
    return 0;
}


