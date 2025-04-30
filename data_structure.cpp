#include <iostream>

using namespace std;

class node {

public:
    node(int elem, node *next = NULL) {
        this->elem = elem;
        this->next = next;
    }

    int elem;
    node *next;
};

class singlylinkedlist {

public:
    singlylinkedlist() {


    }

    void push(int ele, int idx) {
        if (idx >= sz) {cout << "Impossible\n"; return;}
        sz++;
        node* finder;
        finder = head->next;
        for (int i = 1; i <=idx ; ++i) {
            finder = finder->next;
        }

    }

    void pop(int idx) {
        if (idx >= sz || sz < 1) {cout << "Impossible\n"; return;}

    }

    bool empty() {
        if (sz == 0) return true;
        else return false;
    }


private:
    int sz;
    node *head;
    node *tail;
};


int main() {
    singlylinkedlist t1;
t1.empty();

    return 0;
}