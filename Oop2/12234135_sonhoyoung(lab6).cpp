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

class Point {
public:
    Point(int px = 0, int py = 0) {
        x = px;
        y = py;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

protected:
    int x;
    int y;
};

class Square : public Point {
    friend bool comp1(Square a, Square b);

public:
    Square(const string name, int x, int y, unsigned int side = 0) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->side = side;
        this->area = side * side;
    }

    unsigned int getSide() const {
        return side;
    }

    unsigned int getArea() const {
        return area;
    }

    string getName() const {
        return name;
    }

    void setSide(unsigned int side) {
        this->side = side;
    }

    void setArea(unsigned int area) {
        this->area = area;
    }

    void setName(string name) {
        this->name = name;
    }

private:
    unsigned int side;
    unsigned int area{0};
    string name;
};


bool comp1(Square a, Square b) {
    return a.side < b.side;
}

bool comp2(Square a, Square b) {
    return a.getX() < b.getX();
}

bool comp3(Square a, Square b) {
    return a.getY() < b.getY();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    string name;
    int a, b;
    unsigned int c;
    vector<Square> v;
    cout << "Enter the name, lower left corner and side of a square (EOF to end): ";
    while (cin >> name >> a >> b >> c) {
        v.push_back({name, a, b, c});
    }
    cout << "\nSquares in increasing order of area\n";
    sort(v.begin(), v.end(), comp1);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() << ") side=" << v[i].getSide() << "\n";
    }
    cout << "\nSquares in increasing order of x-coordinate\n";
    sort(v.begin(), v.end(), comp2);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() << ") side=" << v[i].getSide() << "\n";
    }
    cout << "\nSquares in increasing order of y-coordinate\n";
    sort(v.begin(), v.end(), comp3);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() << ") side=" << v[i].getSide() << "\n";
    }


    return 0;
}


