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

pll p2v(pll a, pll b) // 두 점 A,B가 주어지면 벡터 AB를 반환
{
    return {b.first - a.first, b.second - a.second};
}

ll ccw(pll v1, pll v2) // 벡터 v1, v2의 CCW
{
    ll rst = v1.first * v2.second - v1.second * v2.first;
    return (rst > 0) ? 1 : (rst < 0) ? -1 : 0;
}

ll dist2(pll a, pll b) // 점 A,B사이의 거리의 제곱
{
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<pll> ans;
    int n;
    cin >> n;
    vector<pll> v(n);
    for (auto &i: v) {
        cin >> i.first >> i.second;
        if (v[0] > i) swap(v[0], i);
    }

    sort(v.begin() + 1, v.end(), [&](pll a, pll b) {
        auto v1 = p2v(v[0], a);
        auto v2 = p2v(v[0], b);
        auto rst = ccw(v1, v2);
        return rst != 0 ? rst > 0 : dist2(v[0], a) < dist2(v[0], b);
    });

    for (auto &i: v) {
        while (ans.size() > 1) {
            auto temp1 = ans[ans.size() - 2];
            auto temp2 = ans[ans.size() - 1];
            auto v1 = p2v(temp1, temp2);
            auto v2 = p2v(temp2, i);

            ll rst = ccw(v1, v2);
            if (rst > 0) break;
            ans.pop_back();

        }
        ans.push_back(i);
    }
    cout << ans.size();

    return 0;
}
