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

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    for (int count=0; count  < 20; ++count)
    {
        // 숫자가 4로 나눌 수 있는 경우 이 반복을 건너뛴다.
        if ((count % 4) == 0)
            continue; // 루프 몸체 끝으로 점프한다.

        // 숫자가 4로 나눌 수 없는 경우 계속된다.
        std::cout << count << std::endl;

        // continue 문은 여기로 이동시킨다.
    }

    return 0;
}
