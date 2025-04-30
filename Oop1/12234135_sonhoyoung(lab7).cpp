#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

unsigned int makeA(unsigned int level);

int makeS(unsigned int level);

unsigned int makeM(unsigned int level);

unsigned int makeD(unsigned int level);


int main() {
    int a;
    int result;
    int ans;
    cout << "Enter a seed of random numbers: ";
    cin >> a;
    srand(a);
    cout << "Select arithmetic (A, S, M, D) and level (1, 2, 3): ";
    string t;
    unsigned int l;
    cin >> t >> l;
    if (t == "A") {
        while (1) {
            result = makeA(l);
            do {
                cin >> ans;
                if (ans == -1) {
                    cout << "Bye!";
                    return 0;
                }
                if (ans == result) {
                    cout << "Correct!\n";
                    break;
                } else {
                    cout << "Wrong answer. Try again." << "\n? ";
                }

            } while (ans != result);
        }

    } else if (t == "S") {
        while (1) {
            result = makeS(l);
            do {
                cin >> ans;
                if (ans == -1) {
                    cout << "Bye!";
                    return 0;
                }
                if (ans == result) {
                    cout << "Correct!\n";
                    break;
                } else {
                    cout << "Wrong answer. Try again." << "\n? ";
                }

            } while (ans != result);
        }


    } else if (t == "M") {
        while (1) {
            result = makeM(l);
            do {
                cin >> ans;
                if (ans == -1) {
                    cout << "Bye!";
                    return 0;
                }
                if (ans == result) {
                    cout << "Correct!\n";
                    break;
                } else {
                    cout << "Wrong answer. Try again." << "\n? ";

                }

            } while (ans != result);
        }


    } else if (t == "D") {
        while (1) {
            result = makeD(l);
            do {
                cin >> ans;
                if (ans == -1) {
                    cout << "Bye!";
                    return 0;
                }
                if (ans == result) {
                    cout << "Correct!\n";
                    break;
                } else {
                    cout << "Wrong answer. Try again." << "\n? ";
                }

            } while (ans != result);
        }
    }


    return 0;
}


unsigned int makeA(unsigned int level) {
    unsigned int x, y{0};
    if (level == 1) {
        x = rand() % 8;
        x = x + 1;
        y = rand() % 8;
        y = y + 1;

    } else if (level == 2) {
        x = rand() % 90;
        x = x + 10;
        y = rand() % 90;
        y = y + 10;

    } else {
        x = rand() % 900;
        x = x + 100;
        y = rand() % 900;
        y = y + 100;
    }


    cout << x << " + " << y << " = ? (-1 to quit) ";

    return x + y;
}


int makeS(unsigned int level) {
    int x, y;
    if (level == 1) {
        x = rand() % 9;
        x = x + 1;
        y = rand() % 9;
        y = y + 1;

    } else if (level == 2) {
        x = rand() % 90;
        x = x + 10;
        y = rand() % 90;
        y = y + 10;

    } else {
        x = rand() % 900;
        x = x + 100;
        y = rand() % 900;
        y = y + 100;
    }
    cout << x << " - " << y << " = ? (-1 to quit) ";


    return x - y;
}


unsigned int makeM(unsigned int level) {
    unsigned int x, y;
    if (level == 1) {
        x = rand() % 9;
        x = x + 1;
        y = rand() % 9;
        y = y + 1;

    } else if (level == 2) {
        x = rand() % 90;
        x = x + 10;
        y = rand() % 90;
        y = y + 10;

    } else {
        x = rand() % 900;
        x = x + 100;
        y = rand() % 900;
        y = y + 100;
    }
    cout << x << " * " << y << " = ? (-1 to quit) ";
    return x * y;
}


unsigned int makeD(unsigned int level) {
    unsigned int x, y;
    if (level == 1) {
        x = rand() % 9;
        x = x + 1;
        y = rand() % 9;
        y = y + 1;

    } else if (level == 2) {
        x = rand() % 90;
        x = x + 10;
        y = rand() % 90;
        y = y + 10;

    } else {
        x = rand() % 900;
        x = x + 100;
        y = rand() % 900;
        y = y + 100;
    }
    cout << x << " / " << y << " = ? (-1 to quit) ";
    return x / y;
}


