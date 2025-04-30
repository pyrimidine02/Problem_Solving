#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pli = pair<ll, int>;


int binarySearch(vll &lis, int left, int right, ll target);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a;
    vll v(a);
    vll lis(a);
    vll out;
    vector<pli> check(a);
    for (int i = 0; i < a; ++i) {
        cin >> v[i];
    }
    lis[0] = v[0];
    check[0] = {v[0] , 0};
    int j = 0;
    for (int i = 1; i < a; ++i) {
        if (lis[j] < v[i]) {
            lis[j + 1] = v[i];
            check[i] = {v[i], j + 1};
            j++;
        } else {
            int pos = binarySearch(lis, 0, j, v[i]);
            lis[pos] = v[i];
            check[i] = {v[i], pos};
        }
    }

    cout << j + 1 << "\n";

    for (int i = check.size() - 1; i >= 0; i--) {
        if (check[i].second == j ) {
            out.push_back(check[i].first);
            j--;
        }
        if (j == -1) break;
    }
    sort(out.begin(), out.end());

    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << " ";
    }

    return 0;
}

int binarySearch(vll &lis, int left, int right, ll target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}
