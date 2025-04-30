#include <iostream>
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

class Rational {
public:
    Rational(int numator = 0, int denominator = 1) {
        if (denominator < 0) {
            denominator *= -1;
            numator *= -1;
        } else if (numator == 0) {
            denominator = 1;
        }

        this->numerator = numator;
        this->denominator = denominator;
    }            // default constructor
    Rational add(const Rational &r1, const Rational &r2) {
        int a = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
        int b = r1.denominator * r2.denominator;
        return Rational(a, b);
    }

    Rational subtract(const Rational &r1, const Rational &r2) {
        int a = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
        int b = r1.denominator * r2.denominator;
        return Rational(a, b);
    }

    Rational multiply(const Rational &r1, const Rational &r2) {
        int a = r1.numerator * r2.numerator;
        int b = r1.denominator * r2.denominator;
        return Rational(a, b);
    }

    Rational divide(const Rational &r1, const Rational &r2) {
        int a = r1.numerator * r2.denominator;
        int b = r1.denominator * r2.numerator;
        return Rational(a, b);
    }

    string toRationalString() {
        reduce();
        string n = to_string(numerator);
        string d = to_string(denominator);
        string rst = n + "/" + d;
        return rst;
    }      // return as string format x/y
    double toDouble() {
        double n = numerator;
        return n / denominator;
    }              // return rational as double
private:
    int numerator;   // numerator
    int denominator; // denominator; positive integer

    //int gcd(int a, int b) {
    //    return (a % b == 0) ? b : gcd(b, a % b);
    //}

    void reduce() {
        int a = numerator;
        int b = denominator;
        if (a < 0) a *= -1;
        if (b < 0) b *= -1;
        int temp;
        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        while (1) {
            if (a % b == 0) break;
            else {
                temp = a;
                a = b;
                b = temp % b;
            }
        }
        numerator /= b;
        denominator /= b;
    }   // convert to irreducible fraction with positive denominator
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    int n, m;
    cout << "Enter the first rational: ";
    cin >> n >> m;
    Rational a(n, m);
    cout << "First rational: " << a.toRationalString() << "\n";
    cout << "Enter the second rational: ";
    cin >> n >> m;
    Rational b(n, m);
    cout << "Second rational: " << b.toRationalString() << "\n";
    Rational ra, rs, rm, rd;
    ra = ra.add(a, b);
    rs = rs.subtract(a, b);
    rm = rm.multiply(a, b);
    rd = rd.divide(a, b);
    cout << fixed << setprecision(2) << a.toRationalString() << " + " << b.toRationalString() << " = "
         << ra.toRationalString() << " = " << ra.toDouble() << "\n";
    cout << fixed << setprecision(2) << a.toRationalString() << " - " << b.toRationalString() << " = "
         << rs.toRationalString() << " = " << rs.toDouble() << "\n";
    cout << fixed << setprecision(2) << a.toRationalString() << " * " << b.toRationalString() << " = "
         << rm.toRationalString() << " = " << rm.toDouble() << "\n";
    cout << fixed << setprecision(2) << a.toRationalString() << " / " << b.toRationalString() << " = "
         << rd.toRationalString() << " = " << rd.toDouble() << "\n";
    return 0;
}
