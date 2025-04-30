#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class StackFullException : public std::runtime_error {
public:
    StackFullException() : std::runtime_error("<<Error>> stack is full") {}
};


class StackEmptyException : public std::runtime_error {
public:
    StackEmptyException() : std::runtime_error("<<Error>> stack is empty") {}
};

class Stack {
public:
    Stack(int cap) {
        capacity = cap;
        curSize = 0;
    }   // capacity=cap, curSize=0으로 초기화
    void push(int x) {
        if (capacity == curSize)
            throw StackFullException{};
        else
            v.push_back(x);
        curSize++;
    }   // 벡터의 push_back 함수 이용하여 구현
    void pop() {
        if (curSize == 0)
            throw StackEmptyException{};
        else
            v.pop_back();
        curSize--;
    }      // 벡터의 pop_back 함수 이용하여 구현
    void print() const {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

private:
    vector<int> v; // 정수 벡터
    int capacity;  // 스텍의 최대 용량
    int curSize;   // 현재 스텍에 있는 데이터의 개수
};


int main() {

    cout << "Enter the stack capacity: ";
    int a, b;
    cin >> a;
    Stack s(a);
    while (cout << "Enter a choice (1 x: push x, 2: pop, 3: print, 4: quit): ", cin >> a) {
        if (a == 4) break;

        switch (a) {
            case 1:
                try {
                    cin >> b;
                    s.push(b);
                } catch (StackFullException &e) {
                    cout << e.what() << "\n";
                }
                break;
            case 2:
                try {
                    s.pop();
                } catch (StackEmptyException &e) {
                    cout << e.what() << "\n";
                }
                break;
            case 3:
                cout << "stack: ";
                s.print();
                break;
            default:
                break;
        }

    }
    cout << "Bye now!";

    return 0;
}


