#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

class point {
public:
    point(string pname = "", int px = 0, int py = 0) {
        name = pname;
        x = px;
        y = py;
    }

    string getName() { return name; }

    int getX() { return x; }

    int getY() { return y; }

    void setName(string pname) { name = pname; }

    void setX(int px) { x = px; }

    void setY(int py) { y = py; }

private:
    string name;
    int x;
    int y;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    int n;
    cout << "Number of points: ";
    cin >> n;
    cin.ignore(100, '\n');

    string str;
    vector<point> v(n);
    for (int i = 0; i < n; ++i) {
        cout << "Name of a point: ";
        getline(cin, str);
        v[i].setName(str);
        cout << "Position of a point: ";
        int a, b;
        cin >> a >> b;
        v[i].setX(a);
        v[i].setY(b);
        cin.ignore(100, '\n');
        cout << v[i].getName() << " " << "(" << v[i].getX() << ", " << v[i].getY() << ")\n\n";
    }

    if (n > 1)
        cout << "Center of " << n << " points: ";
    else
        cout << "Center of " << n << " point: ";

    double r1 = 0;
    double r2 = 0;
    for (int i = 0; i < n; ++i) {
        r1 += v[i].getX();
        r2 += v[i].getY();
    }
    cout << fixed << setprecision(1) << "(" << r1 / n << ", " << r2 / n << ")";

    return 0;
}
