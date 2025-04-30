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

class Complex {
    friend istream &operator>>(istream &, Complex &);

public:
    explicit Complex(double real = 0.0, double imaginary = 0.0) {
        this->real = real;
        this->imaginary = imaginary;
    }

    Complex operator+(const Complex &c) const {
        Complex out;
        out.real = this->real + c.real;
        out.imaginary = this->imaginary + c.imaginary;
        return out;
    }

    Complex operator-(const Complex &c) const {
        Complex out;
        out.real = this->real - c.real;
        out.imaginary = this->imaginary - c.imaginary;
        return out;
    }

    Complex operator*(const Complex &c) const {
        Complex out;
        out.real = (this->real * c.real - this->imaginary * c.imaginary);
        out.imaginary = this->real * c.imaginary + this->imaginary * c.real;
        return out;
    }

    Complex operator/(const Complex &c) const {
        Complex out;
        out.real =
                (this->real * c.real + this->imaginary * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
        out.imaginary =
                (this->imaginary * c.real - this->real * c.imaginary) / (c.real * c.real + c.imaginary * c.imaginary);
        return out;
    }

    string toString() const {
        ostringstream out;
        out << fixed << setprecision(1);
        out << this->real;
        if (this->imaginary >= 0) out << "+";
        out << this->imaginary << "i";
        return out.str();
    }

private:
    double real;               // real part
    double imaginary;          // imaginary part
};

istream &operator>>(istream &in, Complex &c) {

    double a, i = 0.0, r = 0.0;
    in >> a;
    if (in.peek() == 'i') {
        i = a;
        cin.ignore(1);
    } else {
        r = a;
        if(in.peek() != '\n') {
            char s;
            in >> s;
            if (s == '+') {
                in >> i;
                cin.ignore(1);
            } else if (s == '-') {
                in >> i;
                i *= -1;
                cin.ignore(1);
            }
        }
    }
    c = Complex(r, i);

    return in;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Enter the first complex number in the form X + Yi: ";
    Complex a, b;
    cin >> a;
    cin.ignore(100,'\n');
    cout << "Enter the second complex number in the form X + Yi: ";
    cin >> b;
    cout << "(" + a.toString() + ") + (" + b.toString() + ") = " << (a + b).toString() << "\n";
    cout << "(" + a.toString() + ") - (" + b.toString() + ") = " << (a - b).toString() << "\n";
    cout << "(" + a.toString() + ") * (" + b.toString() + ") = " << (a * b).toString() << "\n";
    cout << "(" + a.toString() + ") / (" + b.toString() + ") = " << (a / b).toString() << "\n";


    return 0;
}


