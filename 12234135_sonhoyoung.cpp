#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


class Word {
public:
    Word(string w) {
        word = w;
        this->setCount(1);
    }

    string getWord() {
        return word;
    }

    void setWord(string w) {
        word = w;
    }

    int getCount() const {
        return count;
    }

    void setCount(int c) {
        count = c;
    }

    void increment() {
        count++;
    }

private:
    string word;
    int count;
};


vector<Word> v;

int findword(string s) {
    for (int i = 0; i < v.size(); ++i) {
        if (s == v[i].getWord()) {
            v[i].increment();
            return i;
        }
    }
    return -1;

}

bool comp(Word a, Word b) {

    if (a.getCount() == b.getCount()) {
        return a.getWord() < b.getWord();

    } else {
        return a.getCount() > b.getCount();
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "Enter the file name: ";
    string s, w;
    cin >> s;
    cout << "Word count has been recorded in file \"Words_" << s <<  "\"";
    ifstream inClientFile{s, ios::in};
    ofstream outClientFile{"Words_" + s, ios::out};
    while (inClientFile >> w) {
        if (w.back() == '.' || w.back() == ',' || w.back() == '?' || w.back() == '!') {
            w.pop_back();
        }
        if (findword(w) == -1) {
            v.push_back(w);
        }
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); ++i) {
        outClientFile << v[i].getWord() << ": " << v[i].getCount() << "\n";
    }


    return 0;
}


