#include <iostream>
#include <vector>

using namespace std;
struct hep {
    int arr[100001];
    int size = 0;
};
hep pq;

void up(int a) {
    while (pq.arr[max((a / 2), 1)] > pq.arr[a]) {
        swap(pq.arr[a / 2], pq.arr[a]);
        a = a / 2;
    }
}

void down() {
    int a = 1;
    while (min(pq.arr[a * 2], pq.arr[a * 2 + 1]) < pq.arr[a]) {
        if (pq.arr[a * 2] < pq.arr[a * 2 + 1]) {
            swap(pq.arr[a], pq.arr[a * 2]);
            a = a * 2;
        } else {
            swap(pq.arr[a], pq.arr[a * 2 + 1]);
            a = a * 2 + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < 100000; ++i) {
        pq.arr[i] = 200000;
    }
    while (t--) {
        string s;
        cin >> s;
        if (s == "empty") cout << (pq.size == 0) << "\n";
        else if (s == "size") cout << pq.size << "\n";
        else if (s == "push") {
            int a;
            cin >> a;
            pq.size++;
            pq.arr[pq.size] = a;
            up(pq.size);
        } else if (s == "pop") {
            if (pq.size == 0) cout << "-1\n";
            else {
                cout << pq.arr[1] << "\n";
                pq.arr[1] = 200000;
                swap(pq.arr[1], pq.arr[pq.size]);
                down();
                pq.size--;
            }
        } else if (s == "top") {
            if (pq.size == 0) cout << "-1\n";
            else {
                cout << pq.arr[1] << "\n";
            }
        } else if (s == "second_top") {
            if (pq.size < 2) {
                cout << "Error\n";
                continue;
            }
            int a = pq.arr[1];
            pq.arr[1] = 200000;
            swap(pq.arr[1], pq.arr[pq.size]);
            down();
            pq.size--;
            cout << pq.arr[1] << "\n";
            int temp = pq.arr[1];
            pq.arr[1] = 200000;
            swap(pq.arr[1], pq.arr[pq.size]);
            down();
            pq.size--;
            pq.size++;
            pq.arr[pq.size] = a;
            up(pq.size);
            pq.size++;
            pq.arr[pq.size] = temp;
            up(pq.size);
        }
    }
    return 0;
}