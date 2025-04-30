#include <bits/stdc++.h>

using namespace std;
int dist[1000001];
int path[1000001];
int t, n;

void daikjsatra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    ::memset(dist, 0x3f3f, sizeof(dist));
    pq.push({0, 1});
    while (!pq.empty()) {
        int pos = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist[pos] < d) continue;
        int next = pos * 2;
        if (next > 0 && next <= t) {
            if (dist[next] > d + 1) {
                dist[next] = d + 1;
                pq.push({d + 1, next});
                path[next] = pos;
            }
        }
        next = pos * 3;
        if (next > 0 && next <= t) {
            if (dist[next] > d + 1) {
                dist[next] = d + 1;
                pq.push({d + 1, next});
                path[next] = pos;
            }
        }
        next = pos + 1;
        if (next > 0 && next <= t) {
            if (dist[next] > d + 1) {
                dist[next] = d + 1;
                pq.push({d + 1, next});
                path[next] = pos;
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    if (t == 1) {
        cout << "0\n";
        cout << "1\n";
        return 0;
    }


    daikjsatra();
    cout << dist[t] << "\n";
    queue<int> q;
    q.push(t);
    int start = t;
    while (n != 1) {
        n = path[start];
        q.push(n);
        start = n;
    }
    while (!q.empty()) {
        int out = q.front();
        q.pop();
        cout << out << " ";
    }
    return 0;
}