#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

class Equation {
    friend bool operator==(const Equation &lhs, const Equation &rhs);

    friend Equation operator+(const Equation &lhs, const Equation &rhs);

    friend Equation operator-(const Equation &lhs, const Equation &rhs);

    friend Equation operator*(double lhs, const Equation &rhs);

    friend Equation operator*(const Equation &lhs, double rhs);

    friend ostream &operator<<(ostream &out, const Equation &eq);

public:
    Equation(double coefficients[], int number) : size(number) {
        this->coeff = new double[size];
        for (int i = 0; i < size; ++i) {
            this->coeff[i] = coefficients[i];
        }
    }

    Equation(const Equation &rhs) : size(rhs.size) {
        this->coeff = new double[size];
        for (int i = 0; i < size; ++i) {
            this->coeff[i] = rhs.coeff[i];
        }
    }

    ~Equation() {
        delete[] coeff;
    }

    int degree() const { return size - 1; }

    Equation &operator=(const Equation &rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete[] coeff;
        size = rhs.size;
        coeff = new double[size];
        for (int i = 0; i < rhs.size; ++i) {
            coeff[i] = rhs.coeff[i];
        }
        return *this;
    }


    Equation &operator+=(const Equation &rhs) {
        int m = max(this->degree(), rhs.degree()) + 1;
        double *p = new double[m];
        if (m == this->degree() + 1) {
            for (int i = 0; i < m; ++i) {
                p[i] = this->coeff[i];
            }
            for (int i = abs(this->degree() - rhs.degree()); i < m; ++i) {
                p[i] += rhs.coeff[i - abs(this->degree() - rhs.degree())];
            }
        } else {
            for (int i = 0; i < m; ++i) {
                p[i] = rhs.coeff[i];
            }
            for (int i = abs(this->degree() - rhs.degree()); i < m; ++i) {
                p[i] += this->coeff[i - abs(this->degree() - rhs.degree())];
            }
        }
        Equation result(p, m);
        delete[] p;

        *this = result;
        return *this;
    }


    Equation &operator*=(double rhs) {
        for (int i = 0; i < size; ++i) {
            coeff[i] *= rhs;
        }
        return *this;
    }

private:
    int size;
    double *coeff;
};

Equation operator+(const Equation &lhs, const Equation &rhs) {
    int m = max(lhs.degree(), rhs.degree()) + 1;
    double *p = new double[m];
    if (m == lhs.degree() + 1) {
        for (int i = 0; i < m; ++i) {
            p[i] = lhs.coeff[i];
        }
        for (int i = abs(lhs.degree() - rhs.degree()); i < m; ++i) {
            p[i] += rhs.coeff[i - abs(lhs.degree() - rhs.degree())];
        }
    } else {
        for (int i = 0; i < m; ++i) {
            p[i] = rhs.coeff[i];
        }
        for (int i = abs(lhs.degree() - rhs.degree()); i < m; ++i) {
            p[i] += lhs.coeff[i - abs(lhs.degree() - rhs.degree())];
        }
    }
    Equation result(p, m);
    delete[] p;
    return result;
}

Equation operator-(const Equation &lhs, const Equation &rhs) {
    int m = max(lhs.degree(), rhs.degree()) + 1;
    double *p = new double[m];
    if (m == lhs.degree() + 1) {
        for (int i = 0; i < m; ++i) {
            p[i] = lhs.coeff[i];
        }
        for (int i = abs(lhs.degree() - rhs.degree()); i < m; ++i) {
            p[i] -= rhs.coeff[i - abs(lhs.degree() - rhs.degree())];
        }
    } else {
        for (int i = 0; i < m; ++i) {
            p[i] = rhs.coeff[i] * (-1);
        }
        for (int i = abs(lhs.degree() - rhs.degree()); i < m; ++i) {
            p[i] += lhs.coeff[i - abs(lhs.degree() - rhs.degree())];
        }
    }
    Equation result(p, m);
    delete[] p;
    return result;
}

Equation operator*(const Equation &lhs, double rhs) {
    Equation result(lhs);
    for (int i = 0; i <= result.degree(); ++i) {
        result.coeff[i] *= rhs;
    }
    return result;
}

Equation operator*(double lhs, const Equation &rhs) {
    Equation result(rhs);
    for (int i = 0; i <= result.degree(); ++i) {
        result.coeff[i] *= lhs;
    }
    return result;
}

ostream &operator<<(ostream &out, const Equation &eq) {
    ostringstream ou;

    for (int i = 0; i < eq.size; ++i) {
        if (eq.coeff[i] == 0) continue;
        if (i == 0)
            ou << eq.coeff[i] << "x^" << eq.size - 1 - i;
        else {
            if (i == eq.size - 1) {
                if (eq.coeff[i] >= 0) ou << "+";
                ou << eq.coeff[i];
            } else if (eq.coeff[i] >= 0) {
                ou << "+" << eq.coeff[i] << "x^" << eq.size - 1 - i;
            } else if (i < eq.size - 1) {
                ou << eq.coeff[i] << "x^" << eq.size - 1 - i;
            }
        }
    }
    ou << "=0";
    out << ou.str();
    return out;
}

bool operator==(const Equation &lhs, const Equation &rhs) {
    if (lhs.degree() != rhs.degree()) {
        return false;
    } else {
        for (int i = 0; i < lhs.size; ++i) {
            if (lhs.coeff[i] != rhs.coeff[i])
                return false;
        }
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Number of terms in equation eq1: ";
    int n;
    cin >> n;
    cout << "Coefficients from the highest terms: ";
    double *p1 = new double[n];
    for (int i = 0; i < n; ++i) {
        cin >> p1[i];
    }
    Equation eq1(p1, n);
    delete[] p1;

    int m;
    cout << "Number of terms in equation eq2: ";
    cin >> m;
    cout << "Coefficients from the highest terms: ";
    double *p2 = new double[m];
    for (int i = 0; i < m; ++i) {
        cin >> p2[i];
    }
    Equation eq2(p2, m);
    delete[] p2;

    cout << "eq1: " << eq1 << "\n";
    cout << "eq2: " << eq2 << "\n";
    Equation C = eq1 + eq2;
    cout << "eq1+eq2: " << C << endl;
    if (eq1 == eq2)
        cout << "eq1 and eq2 are equal" << "\n";
    else {
        cout << "eq1 and eq2 are not equal" << "\n";
        Equation D = eq1 - eq2;
        cout << "eq1-eq2: " << D << endl;
    }

    Equation eq3(eq1);
    cout << "eq3 after eq3(eq1): " << eq3 << "\n";
    eq3 += eq2;
    cout << "eq3 after eq3+=eq2: " << eq3 << "\n";
    Equation eq4 = eq3 * 0.5;
    cout << "eq3*0.5: " << eq4 << "\n";
    Equation eq5 = 4 * eq3;
    cout << "4*eq3: " << eq5 << "\n";

    return 0;
}


