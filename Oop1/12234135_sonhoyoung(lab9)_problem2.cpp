#include <iostream>
#include <string>

using namespace std;

bool testPalindrome(string s, size_t left, size_t right);

int main() {
    string s;
    while (cout << "Enter a string (EOF to quit): " && getline(cin, s)) {
        int si = s.length();
        if (testPalindrome(s, 0, si - 1)) {
            cout << "\"" << s << "\"" << " is a palindrome.\n";
        } else if (!testPalindrome(s, 0, si - 1)) {
            cout << "\"" << s << "\"" << " is not a palindrome. \n";
        }
    }

    return 0;
}

bool testPalindrome(string s, size_t left, size_t right) {
    if (left > right) return true;
    while (s.at(left) == ' ' || s.at(left) == '.' || s.at(left) == ',' || s.at(left) == '?') left++;
    while (s.at(right) == ' ' || s.at(right) == '.' || s.at(right) == ',' || s.at(right) == '?') right--;
    if (s.at(left) != s.at(right)) return false;
    return testPalindrome(s, left + 1, right - 1);
}
