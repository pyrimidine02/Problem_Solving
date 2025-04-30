#include <iostream>
#include <vector>

using namespace std;

struct entry {
    int key = 0;
    string val;
    int valid = 0;
    int sibal = 0;

    entry() {
        key = 0;
        val = "";
        valid = 0;
    }

    entry(int key, string val) {
        this->key = key;
        this->val = val;
        this->valid = 1;
    }

    void erase() {
        valid = 2;
    }

    void sibalup() {
        sibal++;
    }

    int sibalp() {
        return sibal;
    }
};

class ht {
public:
    ht(int size, int div) {
        table = new entry[size];
        this->size = size;
        this->div = div;
    }

    void put(int key, string val) {
        int idx = fun1(key);
        int cnt = 1;
        while (table[idx].valid == 1 && cnt <= this->size) {
            idx = fun1(idx + fun2(key));
            cnt++;
        }
        if (cnt > size) return;
        table[idx] = entry(key, val);

    }

    void erase(int key) {
        int idx = fun1(key);
        int cnt = 1;
        while (table[idx].valid != 0 && cnt <= this->size) {
            if (table[idx].valid == 1 && table[idx].key == key) {
                table[idx].erase();
                return;
            }
            idx = fun1(idx + fun2(key));
            cnt++;
        }
        if (cnt > size) return;
    }

    string find(int key) {
        int idx = fun1(key);
        int cnt = 1;
        while (table[idx].valid != 0 && cnt <= size) {
            if (table[idx].valid == 1 && table[idx].key == key) {
                return table[idx].val;
            }
            idx = fun1(idx + fun2(key));
            cnt++;
        }
        return "";
    }

    int fun1(int key) {
        return key % size;
    }

    int fun2(int key) {
        return div - (key % div);
    }

    void upsibal(int key) {
        int idx = fun1(key);
        int cnt = 1;
        while (table[idx].valid != 0 && cnt <= this->size) {
            if (table[idx].valid == 1 && table[idx].key == key) {
                table[idx].sibalup();
                return;
            }
            idx = fun1(idx + fun2(key));
            cnt++;
        }
        cout << "-1\n";
        return;
    }

    int siblap(int key) {
        int idx = fun1(key);
        int cnt = 1;
        while (table[idx].valid != 0 && cnt <= this->size) {
            if (table[idx].valid == 1 && table[idx].key == key) {
                return table[idx].sibalp();
            }
            idx = fun1(idx + fun2(key));
            cnt++;
        }
        if (cnt > size) return -1;
    }

    int size;
    int div;
    entry *table;
};

int sex(string s) {
    int temp = 1;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans += (s[i] - 'a') * temp;
        temp *= 26;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    ht t1(600000, 50021);
    ht t2(600000, 50021);
    while (t--) {
        string s;
        cin >> s;
        if (s == "add") {
            int a;
            string name;
            cin >> a >> name;
            t1.put(a, name);
            t2.put(sex(name), to_string(a));
        } else if (s == "delete") {
            int a;
            cin >> a;
            string name = t1.find(a);
            t1.erase(a);
            t2.erase(sex(name));
        } else if (s == "name") {
            int a;
            cin >> a;
            cout << t1.find(a) << "\n";
        } else if (s == "number") {
            string name;
            cin >> name;
            string ans = t2.find(sex(name));
            if (ans == "") cout << "0\n";
            else cout << ans << "\n";

        } else if (s == "present") {
            string name;
            cin >> name;
            t2.upsibal(sex(name));
            if (t2.find(sex(name)) != "")
                cout << t2.siblap(sex(name)) << "\n";

        } else if (s == "count") {
            int a;
            cin >> a;
            string ans = t1.find(a);
            if (ans == "") cout << "-1\n";
            else cout << t2.siblap(sex(ans)) << "\n";
        }
    }


}
