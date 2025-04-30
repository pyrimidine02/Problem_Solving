#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int parent[101];

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
    vector<pair<double, double>> p;
    vector<pair<double, pii>> v;
    int t;
    cin >> t;
    double a, b;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        p.push_back({a, b});
    }
    for (int i = 0; i < t - 1; ++i) {
        for (int j = i + 1; j < t; ++j) {
            double dis = sqrt(pow((p[i].first - p[j].first), 2) + pow((p[i].second - p[j].second), 2));
            v.push_back({dis, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < t; ++i) {
        parent[i] = i;
    }
    double result = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }
    cout << setprecision(15) << result;

    return 0;
}

