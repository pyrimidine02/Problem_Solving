#include <bits/stdc++.h>

using namespace std;
vector<int>arr;
bool check[10];
int n,m;

void prt_combi() {
    for (int i = 0; i < n + 1; i++) {
        if (check[i]) {
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}
void dfs_combi(int idx, int cnt) {
    if (cnt == m) {
        prt_combi();
        return;
    }
    for (int i = idx; i < n; i++) {
        if (check[i]) continue;
        check[i] = true;
        dfs_combi(i, cnt + 1);
        check[i] = false;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i <n + 1; i++) {
        arr.push_back(i+1);
    }
    dfs_combi(0, 0);

}