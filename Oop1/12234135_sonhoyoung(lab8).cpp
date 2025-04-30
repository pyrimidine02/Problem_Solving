#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

class fraction {
public:

    fraction(int n, int d = 1) {
        num = n;
        den = d;
        setfraction(num, den);
    }

    void setfraction(int n, int d = 1) {

        int di = gcd(n, d);
        int tempn = n / di;
        int tempd = d / di;
        num = tempn;
        den = tempd;
        if (den < 0) {
            num = -num;
            den = -den;
        }

    }

    int getNum() const {
        return num;
    }

    int getDen() const {
        return den;
    }

private:
    int num;
    int den;

};


fraction add(fraction x, fraction y) {
    int num = x.getNum() * y.getDen() + y.getNum() * x.getDen();
    int den = x.getDen() * y.getDen();
    int di = gcd(num, den);
    num /= di;
    den /= di;
    if (den < 0) {
        den = -den;
        num = -num;
    }
    fraction r(num, den);
    num = r.getNum();
    den = r.getDen();
    cout << "(" << x.getNum() << "/" << x.getDen() << ")" << " + " << "(" << y.getNum() << "/" << y.getDen() << ")"
         << " = " << num << "/" << den << "\n";
    return r;
}

fraction subtract(fraction x, fraction y) {
    int num = x.getNum() * y.getDen() - y.getNum() * x.getDen();
    int den = x.getDen() * y.getDen();
    int di = gcd(num, den);
    num /= di;
    den /= di;
    if (den < 0) {
        den = -den;
        num = -num;
    }
    fraction r(num, den);
    num = r.getNum();
    den = r.getDen();
    cout << "(" << x.getNum() << "/" << x.getDen() << ")" << " - " << "(" << y.getNum() << "/" << y.getDen() << ")"
         << " = " << num << "/" << den << "\n";
    return r;
}

fraction multiply(fraction x, fraction y) {
    int num = x.getNum() * y.getNum();
    int den = x.getDen() * y.getDen();
    if (den < 0) {
        den = -den;
        num = -num;
    }
    fraction r(num, den);
    num = r.getNum();
    den = r.getDen();
    cout << "(" << x.getNum() << "/" << x.getDen() << ")" << " * " << "(" << y.getNum() << "/" << y.getDen() << ")"
         << " = " << num << "/" << den << "\n";
    return r;
}

fraction divide(fraction x, fraction y) {
    int numy = y.getDen();
    int deny = y.getNum();
    if (deny < 0) {
        deny = -deny;
        numy = -numy;
    }
    int num = x.getNum() * numy;
    int den = x.getDen() * deny;
    if (den < 0) {
        den = -den;
        num = -num;
    }
    fraction r(num, den);
    num = r.getNum();
    den = r.getDen();
    cout << "(" << x.getNum() << "/" << x.getDen() << ")" << " / " << "(" << y.getNum() << "/" << y.getDen() << ")"
         << " = " << num << "/" << den << "\n";
    return r;
}


int main() {
    cout << "Enter the numerator and denominator of the first fraction: ";
    int a, b;
    cin >> a >> b;
    fraction f1(a, b);
    cout << "First fraction: " << f1.getNum() << "/" << f1.getDen() << "\n";
    cout << "Enter the numerator and denominator of the second fraction: ";
    cin >> a >> b;
    fraction f2(a, b);
    cout << "Second fraction: " << f2.getNum() << "/" << f2.getDen() << "\n";
    add(f1, f2);
    subtract(f1, f2);
    multiply(f1, f2);
    divide(f1, f2);

    return 0;
}
