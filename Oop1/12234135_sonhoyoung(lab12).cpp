#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Candidate {
public:
    static const int maxLength{11};

    Candidate(unsigned candID = 0, const string &candName = "", unsigned v = 0) {
        ID = candID;
        int namelen = candName.length() < 11 ? (int) candName.length() : 10;
        for (int i = 0; i < namelen; i++) {
            *(name + i) = candName[i];
        }
        *(name + namelen) = '\0';
        votes = v;
    }

    void setID(unsigned candID) {
        ID = candID;
    }

    unsigned getID() const {
        return ID;
    }

    void setName(const string &candName) {
        int namelen = candName.length() < 11 ? (int) candName.length() : 10;
        for (int i = 0; i < namelen; ++i) {
            *(name + i) = candName[i];
        }
        *(name + namelen) = '\0';
    }

    string getName() const {
        return name;
    }

    void setVotes(unsigned v) {
        votes = v;
    }

    unsigned getVotes() const {
        return votes;
    }

    void increaseVotes() {
        votes++;
    }

private:
    unsigned ID;
    char name[maxLength];
    unsigned votes;
};


int main() {
    cout << "Enter the number of candidates and polls: ";
    int a, b;
    cin >> a >> b;
    srand(b);
    string s;
    Candidate n[10];
    Candidate *ptr = n;
    cin.ignore(100, '\n');
    for (int i = 0; i < a; ++i) {
        cout << "Enter the name of candidate #" << i + 1 << ": ";
        getline(cin, s);
        (ptr + i)->setName(s);
        (*(ptr + i)).setID(i + 1);
        (*(ptr + i)).setVotes(0);
    }
    int r;
    for (int i = 0; i < b; ++i) {
        r = rand() % a;
        (*(ptr + r)).increaseVotes();
    }

    cout << "\n" << "Results of " << b << " exit polls\n";
    for (int i = 0; i < a; ++i) {
        cout << "Candidate #" << (*(ptr + i)).getID() << ": ";
        int result = (*(ptr + i)).getVotes();
        int f = result / 100;
        result -= f * 100;
        if (result / 10 >= 5) f++;
        for (int j = 0; j < f; ++j) {
            cout << "*";
        }
        result = (*(ptr + i)).getVotes();
        double d = static_cast<double>(result);
        double c = d / b * 100;
        cout << " (" << (*(ptr + i)).getVotes() << " votes, " << fixed << setprecision(2) << c << "%)";
        cout << "\n";
    }
    cout << "\n";
    int max = 0;
    int idx = 0;
    for (int i = 0; i < a; ++i) {
        if (max < (*(ptr + i)).getVotes()) {
            max = (*(ptr + i)).getVotes();
            idx = (*(ptr + i)).getID();
        }
    }
    cout << "Candidate #" << idx << " " << (*(ptr + idx - 1)).getName() << " is likely to win.";
    return 0;
}
