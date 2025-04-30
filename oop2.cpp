#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

struct node {
    string data;
    node *next;
    node *prev;
};

class Dlist {
public:
    Dlist() {
        head = new node;
    }

    void insert(string s, int idx) {
        if (size == 0) {
            node *v = new node;
            v->data = s;
            head->next = v;
            v->prev = head;
            v->next = NULL;
            tail = v;
            size++;
        } else {
            node *temp = head;
            for (int i = 0; i < idx; ++i) {
                temp = temp->next;
            }
            node *v = new node;
            v->data = s;
            v->next = temp->next;
            temp->next = v;
            v->prev = temp;
            if (v->next == NULL) tail = v;
        }
    }

    void erase(int idx) {
        node *temp = head;
        for (int i = 0; i <= idx; ++i) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp->prev->next == NULL) tail = temp->prev;
        delete temp;
    };

    void print() {
        node *temp = head->next;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }


    node *head;
    node *tail;
    int size = 0;

};

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
    while (t--) {
        Dlist l;
        int n, m, k;
        cin >> n >> m >> k;
        int size = n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            l.insert(s, i);
        }
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            if (s == "up") {
                int a;
                cin >> a;
                k = max(0, k - a);

            } else if (s == "down") {
                int a;
                cin >> a;
                k = min(size - 1, k + a);

            } else if (s == "append") {
                size++;
                string n;
                cin >> n;
                k++;
                l.insert(n, k);

            } else if (s == "cut") {
                if (size == 0 || size <= k) continue;
                l.erase(k);
                size--;
                if (k == size) k--;

            }
        }
        l.print();

    }


    return 0;
}