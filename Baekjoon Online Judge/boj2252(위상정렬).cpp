#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;


vi front[32001];
int visited[32001];

void dfs(int a) {
    visited[a] = true;
    for (int i = 0; i < front[a].size(); i++) {
        if(visited[front[a][i]] == false)
            dfs(front[a][i]);
    }
    cout << a << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int A, B;
        cin >> A >> B;
        front[B].push_back(A);
    }

    for (int i = 1; i <= n; i++) {
        if(visited[i] == false)
            dfs(i);
    }

    cout << "\n";

    return 0;
}

