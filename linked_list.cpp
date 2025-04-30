#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

struct node {
    string name;
    int id;
    string major;
    node *next;
};

class link_list {
    node *tail;
    node *head;
    int size = 0;
public:
    link_list() {
        tail = NULL;
        head = NULL;
    }

    void push_front(string name, int id, string major) {
        node *temp = new node;
        temp->name = name;
        temp->id = id;
        temp->major = major;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void push_back(string name, int id, string major) {
        node *temp = new node;
        temp->name = name;
        temp->id = id;
        temp->major = major;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
        size++;
    }

    void pop() {
        node *temp = head->next;
        delete head;
        head = temp;
        size--;
    }

    void insert(string name, int id, string major, int idx) {
        if (idx < size){

        }else{

        }
    }

    void printall() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->name << " " << temp->id << " " << temp->major << "\n";
            temp = temp->next;
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    link_list a;
    string name;
    int id;
    string major;
    while (cin >> name >> id >> major) {
        a.push_back(name, id, major);
    }

    a.printall();

    return 0;
}





