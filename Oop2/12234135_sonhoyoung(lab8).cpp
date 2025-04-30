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

class Point {
public:
    Point(int x = 0, int y = 0, int z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    virtual ~Point() = default;

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getZ() const {
        return z;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setZ(int z) {
        this->z = z;
    }


    virtual string toString() const {
        return "bubble (" + to_string(getX()) + ", " + to_string(getY()) + ", " + to_string(getZ()) + ") ";
    }

private:
    int x;
    int y;
    int z;
};

class Bubble : public Point {
public:
    Bubble(int x, int y, int z, int r = 0) {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
        this->setRadius(r);
        setVolume();
    }

    virtual ~Bubble() = default;

    int getRadius() const {
        return radius;
    }

    void setRadius(int r) {
        this->radius = r;
    }

    double getVolume() const {
        return volume;
    }

    void setVolume() {
        this->volume = (4.0 / 3) * (3.14) * radius * radius * radius;
    }

    virtual string toString() const {
        return Point::toString() + "R=" + to_string(radius);
    }

private:
    int radius{0};
    double volume;
};

Bubble *arr[100];

int overlap(const Bubble &b1, const Bubble &b2) {
    double distance =
            (b1.getX() - b2.getX()) * (b1.getX() - b2.getX()) + (b1.getY() - b2.getY()) * (b1.getY() - b2.getY()) +
            (b1.getZ() - b2.getZ()) * (b1.getZ() - b2.getZ());
    distance = sqrt(distance);
    if (b1.getRadius() + b2.getRadius() < distance)
        return 1;
    else if (b1.getRadius() < distance && b2.getRadius() < distance)
        return 2;
    else if (b1.getRadius() >= distance + b2.getRadius())
        return 3;
    else
        return 4;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    cout << "Enter the center (x, y, z) and radius of a bubble (EOF to end): ";
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Bubble *ptr = new Bubble(a, b, c, d);
    arr[0] = ptr;
    double m = arr[0]->getVolume();
    Bubble *mb = arr[0];
    int idx = 1;
    while (cin >> a >> b >> c >> d) {
        ptr = new Bubble(a, b, c, d);
        arr[idx] = ptr;
        int temp = overlap(*arr[idx - 1], *arr[idx]);
        switch (temp) {
            case 1:
                cout << arr[idx - 1]->toString();
                cout << " and ";
                cout << arr[idx]->toString();
                cout << " are disjoint\n";
                break;
            case 2:
                cout << arr[idx - 1]->toString();
                cout << " and ";
                cout << arr[idx]->toString();
                cout << " partially overlap\n";
                break;
            case 3:
                cout << arr[idx - 1]->toString();
                cout << " includes ";
                cout << arr[idx]->toString();
                cout << "\n";
                break;

            case 4:
                cout << arr[idx - 1]->toString();
                cout << " is included in ";
                cout << arr[idx]->toString();
                cout << "\n";
                break;
        }
        if (m < arr[idx]->getVolume()) {
            m = arr[idx]->getVolume();
            mb = arr[idx];
        }
        idx++;
    }
    cout << "bubble with the largest volume: ";

    cout << mb->toString() << ", ";
    cout << "V=";
    cout << fixed << setprecision(2) << mb->getVolume();

    return 0;
}


