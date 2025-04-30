#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;

int a;



int binarySearch(vector<int> &lis, int left, int right, int target);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    vi v(a);
    vi lis(a);
    for (int i = 0; i < a; ++i) {
        cin >> v[i];
    }
    lis[0] = v[0];
    int j = 0;
    for (int i = 1; i < a; ++i) {
        if (lis[j] < v[i]) {
            lis[j + 1] = v[i];
            j++;
        } else {
            int pos = binarySearch(lis ,0, j, v[i] );
            lis[pos] = v[i];
        }
    }

    cout << j + 1 << "\n";

    return 0;
}

int binarySearch(vector<int> &lis , int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}
