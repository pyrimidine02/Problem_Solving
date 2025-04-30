#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<int> g;
    vector<int> v[10001];
    while (t--) {
        string s;
        cin >> s;
        if (s == "insertVertex") {
            int a;
            cin >> a;
            if (find(g.begin(), g.end(), a) == g.end()) {
                g.push_back(a);
            } else cout << "Exist\n";
        } else if (s == "eraseVertex") {
            int a;
            cin >> a;
            for (auto i: v[a]) {
                remove(v[i].begin(), v[i].end(), a);
                v[i].pop_back();
            }
            remove(g.begin(), g.end(), a);
            g.pop_back();
        } else if (s == "insertEdge") {
            int a, b;
            cin >> a >> b;
            if (find(v[a].begin(), v[a].end(), b) != v[a].end()) cout << "Exist\n";
            else {
                v[a].push_back(b);
                v[b].push_back(a);
            }
        } else if (s == "eraseEdge") {
            int a, b;
            cin >> a >> b;
            if (find(v[a].begin(), v[a].end(), b) == v[a].end()) cout << "None\n";
            else {
                remove(v[a].begin(), v[a].end(), b);
                v[a].pop_back();
                remove(v[b].begin(), v[b].end(), a);
                v[b].pop_back();
            }
        } else if (s == "isAdjacent") {
            int a, b;
            cin >> a >> b;
            if (find(v[a].begin(), v[a].end(), b) != v[a].end()) cout << "True ";
            else cout << "False ";
            ((v[a].size()) > (v[b].size())) ? (cout << b << "\n") : ((v[a].size()) == (v[b].size()) ? cout << min(a, b)
                                                                                                           << "\n" :
                                                                     cout << a << "\n");
        } else if (s == "minVertexInfo") {
            if (g.size() == 0) cout << "-1\n";
            else {
                int min = 999999;
                for (auto i: g) {
                    if (min > i) min = i;
                }
                cout << min << " " << v[min].size() << "\n";
            }
        }
    }
}