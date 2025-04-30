#include <iostream>
#include <cstdlib>

using namespace std;
int rnd[30];
int cnt;
int ma1, ma2, mi1, mi2;

int main() {
    cout << "Select (1: search, 2: max & min adjacent differences): ";
    int a;
    cin >> a;
    srand(100 * a);
    for (int i = 0; i < 30; ++i) {
        rnd[i] = rand() % 20 + 1;
    }
    cout << "Array: ";
    for (int i = 0; i < 30; ++i) {
        cout << rnd[i] << " ";
    }
    cout << "\n";

    if (a == 1) {
        while (1) {
            cout << "Enter an integer to search (-1 to quit): ";
            cnt = 0;
            int t;
            cin >> t;
            if (t == -1)break;
            for (int i = 0; i < 30; ++i) {
                if (rnd[i] == t) {
                    cout << t << " was found at position " << i << "\n";
                    cnt++;
                }
            }
            if (cnt == 0) {
                cout << t << " was not found in the array.\n";
            }
            cout << "\n";
        }
    } else {
        int max = 0;
        int min = 0x3f3f3f3f;
        for (int i = 1; i < 30; ++i) {
            int d = rnd[i - 1] - rnd[i];
            if (d < 0) d = -d;
            if (max < d) {
                max = d;
                ma1 = rnd[i - 1];
                ma2 = rnd[i];
            }
            if (d < min) {
                min = d;
                mi1 = rnd[i - 1];
                mi2 = rnd[i];
            }
        }
        cout << "Maximum adjacent difference: " << max << " (between " << ma1 << " and " << ma2 << ")\n";
        cout << "Minimum adjacent difference: " << min << " (between " << mi1 << " and " << mi2 << ")\n";

    }

    return 0;
}