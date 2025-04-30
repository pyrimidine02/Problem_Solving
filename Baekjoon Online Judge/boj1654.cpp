#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pli = pair<ll, int>;

int binarySearch(vll &v, ll left, ll right, int n) {
    ll mid;
    ll result = 0;
    while (left <= right) {
        ll sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < v.size(); ++i) {
            sum += (v[i] / mid);
        }
        if (sum >= n) {
            result = mid;
            left = mid + 1;

        } else {
            right = mid - 1;
        }

    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    vll v(k);
    ll max = 0;
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
        if (v[i] > max) max = v[i];
    }
    sort(v.begin(), v.end());
    int r = binarySearch(v, 1, max, n);
    cout << r << "\n";


    return 0;
}