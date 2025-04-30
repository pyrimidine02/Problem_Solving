#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

ll gcd(ll a, ll b) {
    for (; b; a %= b, swap(a, b));
    return a;
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vi graph[10001];
vi rgraph[10001];
bool check[10001];
stack<int> st;
vector<vi> scc;

void dfs(int v) {
    check[v] = 1;
    for (auto i: graph[v]) {
        if (!check[i]) dfs(i);
    }
    st.push(v);
}

void dfs_(int v) {
    check[v] = 1;
    scc.back().push_back(v);
    for (auto i: rgraph[v]) {
        if (!check[i]) dfs_(i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    for (int i = 1; i <= v; ++i) {
        if (!check[i])dfs(i);
    }
    memset(check, 0, sizeof(check));
    while (!st.empty()) {
        int a = st.top();
        st.pop();
        if (!check[a]) {
            scc.emplace_back();
            dfs_(a);
            sort(scc.back().begin(), scc.back().end());
        }
    }
    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for (auto i: scc) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "-1\n";
    }

    return 0;
}