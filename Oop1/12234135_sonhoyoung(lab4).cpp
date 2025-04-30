#include <iostream>

using namespace std;

int main() {
    int a, b{0}, c{0}, d{0}, e{0}, f{0}, z{0};

    cout << "Number of students: ";
    cin >> a;
    int k = 1;
    while (k <= a) {
        cout << "Class type you prefer (1, 2, 3 or 4): ";
        cin >> z;

        if (z == 1) {
            b = b + 1;
        } else if (z == 2) {
            c = c + 1;
        } else if (z == 3) {
            d = d + 1;
        } else if (z == 4) {
            e = e + 1;
        } else {
            f = f + 1;
        }
        k = k + 1;
    }
    cout << "\n";
    cout << "Result of survey" << "\n";
    cout << "1. In-person class: " << b << "\n";
    cout << "2. Live online class: " << c << "\n";
    cout << "3. Pre-recorded online class: " << d << "\n";
    cout << "4. Makeup class: " << e << "\n";
    cout << "5. No or wrong response: " << f << "\n";
    cout << "\n";


    if (b >= c) {
        if (b >= d) {
            if (b >= e) {
                cout << "The most preferred class: In-person class";
            } else if (c >= d) {
                if (c >= e) {
                    cout << "The most preferred class: Live online class";
                } else if (d >= e) {
                    cout << "The most preferred class: Pre-recorded online class";
                } else {
                    cout << "The most preferred class: Makeup class";
                }


            } else if (d >= e) {
                cout << "The most preferred class: Pre-recorded online class";
            } else {
                cout << "The most preferred class: Makeup class";
            }


        } else if (c >= d) {
            if (c >= e) {
                cout << "The most preferred class: Live online class";
            } else if (d >= e) {
                cout << "The most preferred class: Pre-recorded online class";
            } else {
                cout << "The most preferred class: Makeup class";
            }


        } else if (d >= e) {
            cout << "The most preferred class: Pre-recorded online class";
        } else {
            cout << "The most preferred class: Makeup class";
        }


    } else if (c >= d) {
        if (c >= e) {
            cout << "The most preferred class: Live online class";
        } else if (d >= e) {
            cout << "The most preferred class: Pre-recorded online class";
        } else {
            cout << "The most preferred class: Makeup class";
        }


    } else if (d >= e) {
        cout << "The most preferred class: Pre-recorded online class";
    } else {
        cout << "The most preferred class: Makeup class";
    }

    return 0;
}

