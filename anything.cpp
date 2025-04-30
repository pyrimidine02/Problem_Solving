#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << "Encoded string: " << run_length_encoding(s);
    return 0;
}