#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>


using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
//using pii = pair<int, int>;
//using pli = pair<ll, int>;
//using pll = pair<ll, ll>;
//using vi = vector<int>;
//using vll = vector<ll>;
//using vpii = vector<pii>;

class Quadratic {
    friend Quadratic add(Quadratic &q1, Quadratic &q2);

    friend Quadratic subtract(Quadratic &q1, Quadratic &q2);

public:
    Quadratic(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    std::string toString() {
        ostringstream out;
        out << a << "x^2";
        if (b >= 0)
            out << '+' << b << 'x';
        else
            out << b << 'x';
        if (c >= 0)
            out << '+' << c;
        else
            out << c;
        out << "=0";
        return out.str();
    }

    void solve() {
        if ((b * b - 4 * a * c) < 0) {
            cout << "No real roots\n";
        } else if ((b * b - 4 * a * c) == 0) {
            cout << fixed << setprecision(2) << "x=" << (-1 * b) / (2 * a) << "\n";
        } else {
            cout << fixed << setprecision(2) << "x=" << (-1 * b + sqrt((b * b - 4 * a * c))) / (2 * a) << " or "
                 << (-1 * b - sqrt((b * b - 4 * a * c))) / (2 * a) << "\n";
        }
    }

private:
    double a{1};
    double b{0};
    double c{0};
};

Quadratic add(Quadratic &q1, Quadratic &q2) {
    Quadratic a(0, 0, 0);
    a.a = q1.a + q2.a;
    a.b = q1.b + q2.b;
    a.c = q1.c + q2.c;
    return a;
}

Quadratic subtract(Quadratic &q1, Quadratic &q2) {
    Quadratic a(0, 0, 0);
    a.a = q1.a - q2.a;
    a.b = q1.b - q2.b;
    a.c = q1.c - q2.c;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
////    freopen("../output.txt", "w", stdout);
//#endif
    double a, b, c;
    cout << "Enter 3 coefficients of the first quadratic equation: ";
    cin >> a >> b >> c;
    if (a == 0) throw invalid_argument("0");
    Quadratic q1{a, b, c};
    cout << "First equation: " << q1.toString() << "\n";
    cout << "Enter 3 coefficients of the second quadratic equation: ";
    cin >> a >> b >> c;
    Quadratic q2{a, b, c};
    cout <<"Second equation: " << q2.toString() << "\n\n";
    cout << "Solution of " << q1.toString() << ": ";
    q1.solve();
    cout << "Solution of " << q2.toString() << ": ";
    q2.solve();
    cout << "\n";
    cout << "(" << q1.toString() << ")+(" << q2.toString() << ")=" << add(q1, q2).toString() << "\n";
    cout << "(" << q1.toString() << ")-(" << q2.toString() << ")=" << subtract(q1, q2).toString();

    return 0;
}
