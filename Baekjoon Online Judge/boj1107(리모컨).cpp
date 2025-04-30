#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<int> broken;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        broken.push_back(b);
    }

    int ans = abs(n - 100);

    for (int i = 0; i <= 1000000; i++) {
        bool possible = true;
        int len = 0;
        if (i == 0) {
            if (find(broken.begin(), broken.end(), i) != broken.end()) {
                possible = false;
            } else {
                len = 1;
            }
        } else {
            int num = i;
            while (num > 0) {
                int digit = num % 10;
                if (find(broken.begin(), broken.end(), digit) != broken.end()) {
                    possible = false;
                    break;
                }
                len++;
                num /= 10;
            }
        }
        if (possible) {
            ans = min(ans, abs(n - i) + len);
        }
    }

    cout << ans << endl;
    return 0;
}
