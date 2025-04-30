#include <iostream>
#include <iomanip>

using namespace std;

void swap(int *const p1, int *const p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selection_sort(int a[], const int size, int order) {
    if (order == 1) {
        int cnt = 0;
        for (int i = 0; i < size - 1; i++) {
            int idx = 0;
            int min = 111;
            for (int i = cnt; i < size; ++i) {
                if (min > a[i]) {
                    min = a[i];
                    idx = i;
                }
            }
            swap(&a[cnt], &a[idx]);
            cout << "after " << cnt << "-th iteration:";
            for (int i = 0; i < size; ++i) {
                cout << setw(4) << a[i];
            }
            cout << "\n";
            cnt++;
        }
        cout << "Sorted in ascending order:";
        for (int i = 0; i < 10; ++i) {
            cout << setw(4) << a[i];
        }
    } else {
        int cnt = 0;
        for (int i = 0; i < size - 1; ++i) {
            int idx = 0;
            int max = -111;
            for (int i = cnt; i < size; ++i) {
                if (max < a[i]) {
                    max = a[i];
                    idx = i;
                }
            }
            swap(&a[cnt], &a[idx]);
            cout << "after " << cnt << "-th iteration:";
            for (int i = 0; i < size; ++i) {
                cout << setw(4) << a[i];
            }
            cout << "\n";
            cnt++;

        }
        cout << "Sorted in descending order:";
        for (int i = 0; i < 10; ++i) {
            cout << setw(4) << a[i];
        }
    }
}


int main() {
    int a[10];
    cout << "Enter 10 integers in [-99, 99] to sort: ";
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    int t;
    cout << "Choose sorting order (1: ascending order, 2: descending order): ";
    cin >> t;
    cout << "Initial array:";
    for (int i = 0; i < 10; ++i) {
        cout << setw(4) << a[i];
    }
    cout << "\n";
    selection_sort(a, 10, t);

    return 0;
}
