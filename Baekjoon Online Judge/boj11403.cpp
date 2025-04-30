#include <bits/stdc++.h>

using namespace std;

vector<int> v[100];
bool check[100];

void dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (!check[v[x][i]]) {
            check[v[x][i]] = 1;
            dfs(v[x][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a)v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        memset(check, 0, sizeof(check));
        dfs(i);
        for (int j = 0; j < n; j++)
            cout << check[j] << " ";
        cout << "\n";
    }
    return 0;
}