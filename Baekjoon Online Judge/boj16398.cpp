#include <bits/stdc++.h>

using namespace std;


vector<pair<int, pair<int, int>>> v;
int parent[1001];


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
    int n;
    long long result = 0;
    cin >> n;


    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            v.push_back({a, {j, i}});
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }


    cout << result;


    return 0;
}

