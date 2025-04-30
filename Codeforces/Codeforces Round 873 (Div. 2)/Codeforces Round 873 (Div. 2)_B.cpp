#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a;
        cin >> a;
        int ans =0;
        if(a!=1) ans = abs(a-1);
        for (int i = 2; i <= n; ++i) {
            cin >> a;
            if(a==i) continue;
            ans = gcd(ans, abs(a - i));
        }
        cout << ans <<"\n";

    }

    return 0;
}