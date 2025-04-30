#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

vi v[51];
vi in_degree(51);
bool visited[51];
queue<int> q;

void Topology_Sort(int N) {
    for (int i = 1; i <= N; i++) {
        if (q.empty()) {
            cout << "NO\n";
            return;
        }
        int cur = q.front();
        q.pop();
        for (int next: v[cur]) {
            if (--in_degree[next] == 0)q.push(next);
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visited, 0, sizeof(visited));
    int t;
    cin >> t;
    string s[t + 1];
    for (int i = 1; i <= t; ++i) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (s[i][j] == 'Y' && s[j][i] != 'Y') {
                v[i].push_back(j);
                in_degree[j]++;
            }
        }
    }

    for (int i = 1; i <= t; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    Topology_Sort(t);

    return 0;
}

