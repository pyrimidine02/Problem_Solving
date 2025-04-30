#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

class Shape {
public:
    Shape(int x = 0, int y = 0, int z = 0, int r = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
    }

protected:
    int x, y, z, r;
};

class cylinder : public Shape {

public:
    cylinder(int x, int y, int z, int r, int h = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        this->h = h;
    }

    string volume() {
        ostringstream out;
        double v = 1;
        v *= (3.14 * (this->r) * (this->r) * this->h);
        out << fixed << setprecision(2) << v;
        return out.str();
    }

    string location() {
        ostringstream out;
        out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
        return out.str();
    }

private:
    int h;

};

class sphere : public Shape {

public:
    sphere(int x, int y, int z, int r) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
    }

    string volume() {
        ostringstream out;
        double v = 4;
        v /= 3;
        v *= (3.14 * this->r * this->r * this->r);
        out << fixed << setprecision(2) << v;
        return out.str();
    }

    string location() {
        ostringstream out;
        out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
        return out.str();
    }

};

class cone : public Shape {

public:
    cone(int x, int y, int z, int r, int h = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        this->h = h;
    }

    string volume() {
        ostringstream out;
        double v = 1;
        v /= 3;
        v *= (3.14 * this->r * this->r * this->h);
        out << fixed << setprecision(2) << v;
        return out.str();
    }

    string location() {
        ostringstream out;
        out << "(" << this->x << ", " << this->y << ", " << this->z << ")";
        return out.str();
    }

private:
    int h;


};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    string s;
    int x, y, z, r, h;
    while (cout << "Shape type (y: cylinder, s: sphere, c: cone, EOF: to end): " && cin >> s) {
        if (s == "y") {
            cout << "Center position, radius and height of the cylinder (x y z r h): ";
            cin >> x >> y >> z >> r >> h;
            cylinder a(x, y, z, r, h);
            cout << "Volume of the cylinder: " << a.volume() << "\n";
            cout << "Drawing of the cylinder at " << a.location() << "\n\n";


        } else if (s == "s") {
            cout << "Center position and radius of the sphere (x y z r): ";
            cin >> x >> y >> z >> r;
            sphere b(x, y, z, r);
            cout << "Volume of the sphere: " << b.volume() << "\n";
            cout << "Drawing of the sphere at " << b.location() << "\n\n";

        } else {
            cout << "Center position, radius and height of the cone (x y z r h): ";
            cin >> x >> y >> z >> r >> h;
            cone c(x, y, z, r, h);
            cout << "Volume of the cone: " << c.volume() << "\n";
            cout << "Drawing of the cone at " << c.location() << "\n\n";

        }


    }


    return 0;
}


