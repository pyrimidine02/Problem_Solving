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

    while (t--) {
        ll h;
        int n;
        cin >> h >> n;

        vector<pair<ll, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first; // damage
        }
        for (int i = 0; i < n; ++i) {
            cin >> v[i].second; // cooldown
        }

        // 우선 공격이 강하고, 쿨다운이 적은 순서로 정렬합니다.
        sort(v.begin(), v.end(), [](const pair<ll, int> &a, const pair<ll, int> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        ll total_damage = 0;
        vector<ll> vv(n, 0);
        int turns = 0;

        // 최소 쿨다운을 빠르게 찾기 위해 우선순위 큐 사용
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < n; ++i) {
            pq.push(0);
        }

        while (h > 0) {
            ll damage_this_turn = 0;
            while (!pq.empty() && pq.top() <= turns) {
                int idx = pq.top();
                pq.pop();
                damage_this_turn += v[idx].first;
                pq.push(turns + v[idx].second);
            }

            if (damage_this_turn == 0) {
                turns = pq.top();
                continue;
            }

            h -= damage_this_turn;
            ++turns;
        }

        cout << turns << "\n";
    }

    return 0;
}