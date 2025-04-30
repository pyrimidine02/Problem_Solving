#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class ClientData {
public:
    ClientData(int num = 0, string first = "", string last = "", double purchase = 0.0, double unpaid = 0.0) {
        setAccountNumber(num);
        setFirstName(first);
        setLastName(last);
        setPurchase(purchase);
        setUnpaid(unpaid);
    }

    void setAccountNumber(int num) {
        accountNumber = num;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void setFirstName(string first) {
        int len;
        (first.size() < 10) ? len = first.size() : len = 9;
        for (int i = 0; i < len; ++i) {
            firstName[i] = first[i];
        }
        firstName[len] = '\0';

    }

    string getFirstName() const {
        return firstName;
    }

    void setLastName(string last) {
        int len;
        (last.size() < 10) ? len = last.size() : len = 9;
        for (int i = 0; i < len; ++i) {
            firstName[i] = last[i];
        }
        firstName[len] = '\0';
    }

    string getLastName() const {
        return lastName;
    }

    void setPurchase(double purchase) {
        this->purchase = purchase;
    }

    double getPurchase() const {
        return purchase;
    }

    void setUnpaid(double unpaid) {
        this->unpaid = unpaid;
    }

    double getUnpaid() const {
        return unpaid;
    }

private:
    int accountNumber;   // 계좌번호. [1, 100] 사이의 정수
    char firstName[10];  // 이름
    char lastName[10];   // 성
    double purchase;     // 전월 카드 사용액
    double unpaid;       // 미결재 금액
};

int main() {
    cout << "Enter file name: ";
    string s;
    cin >> s;
    fstream inout{s, ios::in | ios::out};
    fstream out_txt{s + ".txt", ios::out};
    fstream out_dat{s + ".dat", ios::out | ios::binary};
    cout << "Output has been written to " + s + ".dat and " + s + ".txt.";
    int num;
    double purchase, unpaid;
    string first, last;
    while (inout >> num >> first >> last >> purchase >> unpaid) {
        ClientData client(num, first, last, purchase, unpaid);
        out_dat.seekp((client.getAccountNumber() - 1) * sizeof(ClientData), ios::beg);
        out_dat.write(reinterpret_cast<const char *>(&client), sizeof(ClientData));
    }
    inout.clear();
    inout.seekg(0, ios::beg);

    out_txt << "Gold class:\n";
    while (inout >> num >> first >> last >> purchase >> unpaid) {
        if (unpaid == 0 && purchase >= 3000) {
            out_txt << setw(3) << setfill('0') << num << " " << setfill(' ') << setw(9) << left << first << setw(9)
                    << last << setw(14) << fixed << setprecision(2) << right << purchase << setw(14) << unpaid
                    << "\n";
        }
    }
    out_txt << "\n";
    inout.clear();
    inout.seekg(0, ios::beg);
    out_txt << "Silver class:\n";
    while (inout >> num >> first >> last >> purchase >> unpaid) {
        if (unpaid == 0 && purchase < 3000) {
            out_txt << setw(3) << setfill('0') << num << " " << setfill(' ') << setw(9) << left << first << setw(9)
                    << last << setw(14) << fixed << setprecision(2) << right << purchase << setw(14) << unpaid
                    << "\n";
        }
    }
    out_txt << "\n";
    inout.clear();
    inout.seekg(0, ios::beg);
    out_txt << "Bronze class:\n";
    while (inout >> num >> first >> last >> purchase >> unpaid) {
        if (unpaid != 0) {
            out_txt << setw(3) << setfill('0') << num << " " << setfill(' ') << setw(9) << left << first << setw(9)
                    << last << setw(14) << fixed << setprecision(2) << right << purchase << setw(14) << unpaid
                    << "\n";
        }
    }
    out_txt << "\n";
    inout.clear();
    inout.seekg(0, ios::beg);
    char in;
    while (inout >> in) {
        string check = "aeiouAEIOU";
        if (check.find(in) != string::npos) {
            inout.seekg(-1, ios::cur);
            inout.put('*');
            inout.seekg(inout.tellp(), ios::beg);
        }
    }


    return 0;
}


