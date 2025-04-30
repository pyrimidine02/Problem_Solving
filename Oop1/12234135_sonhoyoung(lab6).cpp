#include <iostream>
#include <string>


using namespace std;

int main() {

    string t;
    int a;
    cout << "Select triangle type (a, b, c, d): ";
    cin >> t;
    if (t != "a")
        if (t != "b")
            if (t != "c")
                if (t != "d") {
                    cout << "Invalid input. Enter again: ";
                    cin >> t;
                }

    cout << "Enter base length [1, 20]: ";
    cin >> a;
    if (a < 1) {
        cout << "Invalid input. Enter again: ";
        cin >> a;
    }
    if (a > 20) {
        cout << "Invalid input. Enter again: ";
        cin >> a;
    }


    if (t == "a") {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j <= i; j++) {
                cout << "*";
                if (j == i) break;
                cout << " ";
            }
            cout << "\n";
        }
    }

    if (t == "b") {
        for (int i = a; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                cout << "*";
                if (j == i - 1) break;
                cout << " ";
            }
            cout << "\n";
        }
    }

    if (t == "c") {
        for (int i = a; i > 0; i--) {

            for (int j = 0; j < a - i; j++) {
                cout << " ";
                cout << " ";
            }

            for (int j = 0; j < i; j++) {
                cout << "*";
                if (j == i - 1) break;
                cout << " ";
            }


            cout << "\n";
        }
    }

    if (t == "d") {
        for (int i = 0; i < a; i++) {

            for (int j = a - i; j > 0; j--) {
                cout << " ";
                cout << " ";
            }

            for (int j = 0; j <= i; j++) {
                cout << "*";
                if (j == i) break;
                cout << " ";
            }


            cout << "\n";
        }
    }


    return 0;
}


