#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

void printVector1(const vi &v, string s);

void printVector2(const vi &v);


int main() {
    vi a;
    vi b;
    vi a2;
    vi b2;
    vi un;
    vi ins;

    cout << "Enter nonredundant, positive integers for A (-1 to end): ";
    while (1) {
        int t = 0;
        int in;
        cin >> in;
        if (in == -1) break;
        for (int i = 0; i < a.size(); ++i) {

            if (a.at(i) == in) {
                a2.push_back(in);
                break;
            }
            t++;
        }
        if (t == a.size()) a.push_back(in);
    }
    printVector1(a2, "A");
    cout << "Enter nonredundant, positive integers for B (-1 to end): ";
    while (1) {
        int t = 0;
        int in;
        cin >> in;
        if (in == -1) break;
        for (int i = 0; i < b.size(); ++i) {

            if (b.at(i) == in) {
                b2.push_back(in);
                break;
            }
            t++;
        }
        if (t == b.size()) b.push_back(in);
    }
    printVector1(b2, "B");
    cout << "A before sorting: { ";
    printVector2(a);
    cout << "B before sorting: { ";
    printVector2(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << "A after sorting: { ";
    printVector2(a);
    cout << "B after sorting: { ";
    printVector2(b);
    for (int i = 0; i < a.size(); ++i) {
        un.push_back(a.at(i));
    }

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a.at(i) == b.at(j)) {
                ins.push_back(b.at(j));
            }
        }
    }

    for (int i = 0; i < b.size(); ++i) {
        if(!binary_search(a.begin(),a.end(),b[i]))
            un.push_back(b[i]);

    }
    if (!un.empty()) sort(un.begin(), un.end());
    if (!ins.empty()) sort(ins.begin(), ins.end());

    cout << "A union B: { ";
    printVector2(un);
    cout << "A intersection B: { ";
    printVector2(ins);

    return 0;
}

void printVector1(const vi &v, string s) {
    for (auto const re: v) {
        cout << "Duplicate number in " << s << ": " << re << "\n";
    }
}

void printVector2(const vi &v) {
    for (auto const re: v) {
        cout << re << " ";
    }
    cout << "}\n";
}
