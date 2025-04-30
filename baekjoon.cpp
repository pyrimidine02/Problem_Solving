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

vi graph[20001];
vi rgraph[20001];
bool check[20001];
stack<int> st;
vector<vi> scc;
int ans[10001];

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
    vi temp;
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        int temp1 = a, temp2 = b;
        a *= -1;
        if (a < 0) a = 10000 + abs(a);
        if (b < 0) b = 10000 + abs(b);
        temp.push_back(a);
        temp.push_back(b);
        graph[a].push_back(b);
        rgraph[b].push_back(a);
        a = temp1, b = temp2;
        b *= -1;
        if (a < 0) a = 10000 + abs(a);
        if (b < 0) b = 10000 + abs(b);
        temp.push_back(a);
        temp.push_back(b);
        graph[b].push_back(a);
        rgraph[a].push_back(b);
    }
    for (auto i: temp) {
        if (!check[i])dfs(i);
    }
    memset(check, 0, sizeof(check));
    while (!st.empty()) {
        int a = st.top();
        st.pop();
        if (!check[a]) {
            scc.emplace_back();
            dfs_(a);
//            sort(scc.back().begin(), scc.back().end());
        }
    }
    sort(scc.begin(), scc.end());
    memset(check, 0, sizeof(check));


    for (auto &i: scc) {
        for (auto &j: i) {
            if (j > 10000) {
                if (check[j - 10000]) {
                    cout << "0";
                    return 0;
                } else check[j] = true;
            } else {

                if (check[j + 10000]) {
                    cout << "0";
                    return 0;
                } else check[j] = true;
            }
        }
        memset(check, 0, sizeof(check));
        fill(ans, ans + 10000, -1);
    }

    cout << "1\n";
    vi value(v + 1, -1);
    for (int i = scc.size() - 1; i >= 0; --i) {
        for (int j: scc[i]) {
            int var = (j <= 10000 ? j : j - 10000);
            bool is_negated = (j > 10000);

            if(value[var] == -1) {
                value[var] = !is_negated;
            }
        }
    }

    for (int i = 1; i <= v; ++i) {
        cout << value[i] << " ";
    }
    cout << "\n";



#ifndef ONLINE_JUDGE
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}