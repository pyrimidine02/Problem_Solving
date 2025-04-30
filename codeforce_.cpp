#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
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


vi Sort(vi v, int l , int r){
    int l2 = l , r2 = r;
    while (l2 < r2){
        int l1 =l , r1 = r;
        int pivot = v[l2];

        while (true)
        {
            while (l2 <= r2 && v[l2] <= pivot)
                ++l2;
            while (l2 <= r2 && v[r2] > pivot)
                --r2;

            if (l2 > r2)
                break;
            swap(v[l2], v[r2]);
        }
        swap(pivot, v[r2]);

        if


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
    int a,b;
    cin >> a >> b;
    

#ifndef ONLINE_JUDGE
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
}
