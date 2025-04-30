#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int parent[100001];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return true;
    else return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        parent[i] = i;
    }
    vector<pli> x;
    vector<pli> y;
    vector<pli> z;
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<pair<ll, pair<int, int>>> v;
    for (int i = 1; i < t; ++i) {
        v.push_back({abs(x[i].first - x[i - 1].first), {x[i].second, x[i - 1].second}});
        v.push_back({abs(y[i].first - y[i - 1].first), {y[i].second, y[i - 1].second}});
        v.push_back({abs(z[i].first - z[i - 1].first), {z[i].second, z[i - 1].second}});
    }
    sort(v.begin(), v.end());
    int result = 0;

    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }
    cout << result;

    return 0;
}

