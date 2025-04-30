#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cout << "Enter number of online orders or customer name on separate lines (EOF to end): ";
    int i;
    int sum = 0, error = 0;
    vector<string> v;
    while (1) {
        cin >> i;
        if (cin.eof()) break;
        if (cin.fail()) {
            cout << "cin.eof(): " << cin.eof() << ", cin.fail(): " << cin.fail() << ", cin.bad(): " << cin.bad()
                 << ", cin.good(): " << cin.good() << "\n";
            cin.clear();
            string s;
            getline(cin, s);
            v.push_back(s);
            error++;
        } else {
            sum += i;
            cout << "cin.eof(): " << cin.eof() << ", cin.fail(): " << cin.fail() << ", cin.bad(): " << cin.bad()
                 << ", cin.good(): " << cin.good() << "\n";
        }
    }
    cout << "cin.eof(): " << cin.eof() << ", cin.fail(): " << cin.fail() << ", cin.bad(): " << cin.bad()
         << ", cin.good(): " << cin.good() << "\n";
    cout << "Number of online orders: " << sum << "\n";
    cout << "Number of offline customers: " << error << "\n";
    for (int j = 0; j < error; ++j) {
        cout << v[j] << "\n";
    }
    return 0;
}


