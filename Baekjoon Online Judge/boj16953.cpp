#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int bfs(long long a, long long b) {
    queue<pair<long long, long long> > q;
    q.push({a, 1});
    while (!q.empty()) {
        pair<long long, long long> l = q.front();
        q.pop();
        if (l.first == b) {
            return l.second;
        }
        if (l.first * 2 <= b) {
            q.push({l.first * 2, l.second + 1});
        }
        if (l.first * 10 + 1 <= b) {
            q.push({l.first * 10 + 1, l.second + 1});
        }
    }
    return -1;
}

int main() {
    long long a, b;

    cin >> a >> b;
    cout << bfs(a, b);
    return 0;
}