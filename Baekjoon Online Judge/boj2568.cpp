#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
struct node {
    ll right;
    int idx;
    ll left;
};

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<pii> v;
    vll lis(t);
    vll out;
    vector<node> check(t);
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    lis[0] = v[0].second;
    check[0] = {v[0].second, 0, v[0].first};
    int j = 0;
    for (int i = 1; i < t; ++i) {
        if (lis[j] < v[i].second) {
            lis[j + 1] = v[i].second;
            check[i] = {v[i].second, j + 1, v[i].first};
            j++;
        } else {
            int pos = binarySearch(lis, 0, j, v[i].second);
            lis[pos] = v[i].second;
            check[i] = {v[i].second, pos, v[i].first};
        }
    }
    cout << t - (j + 1) << "\n";

    for (int i = check.size() - 1; i >= 0; i--) {
        if (check[i].idx == j) {
            j--;
        } else out.push_back(check[i].left);

    }
    sort(out.begin(), out.end());

    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << "\n";
    }

    return 0;
}

