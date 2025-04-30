#include <iostream>
#include <iomanip>
#include <vector>
#include <array>  // Include <array> for std::array
#include <algorithm> // Include <algorithm> for std::sort

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

class Date {
    friend ostream &operator<<(ostream &, const Date &);

    friend istream &operator>>(istream &, Date &); // Removed const

    friend class Baby;

public:
    Date(int m = 1, int d = 1, int y = 1900); // default constructor
    Date &operator++(); // prefix increment operator
    Date operator++(int); // postfix increment operator
    Date &operator+=(unsigned int); // add days, modify object
    static bool leapYear(int); // is year a leap year?
    bool endOfMonth(int) const; // is day at the end of month?
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const std::array<unsigned int, 13> days; // days per month
    void helpIncrement(); // utility function for incrementing date
};

const array<unsigned int, 13> Date::days{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {} // Constructor implementation

Date &Date::operator+=(unsigned int additionalDays) {
    for (unsigned int i = 0; i < additionalDays; ++i) {
        helpIncrement();
    }
    return *this; // enables cascading
}

bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
}

bool Date::endOfMonth(int testDay) const {
    if (month == 2 && leapYear(year))
        return testDay == 29; // last day of Feb. in leap year
    else return testDay == days[month];
}

void Date::helpIncrement() {
    if (!endOfMonth(day))
        ++day; // increment day
    else {
        if (month < 12) { // day is end of month and month < 12
            ++month; // increment month
            day = 1; // first day of new month
        } else { // last day of year
            ++year; // increment year
            month = 1; // first month of new year
            day = 1; // first day of new month
        }
    }
}

class Baby {
public:
    void setName(const string &name) { // Changed to const string reference
        this->name = name;
    }

    void setBirthDate(const Date &birthDate) { // Changed to const Date reference
        this->birthDate = birthDate;
    }

    void sethundred(const Date &hundredDate) { // Changed to const Date reference
        this->hundredDate = hundredDate;
    }

    string getName() const {
        return name;
    }

    Date getBirthDate() const {
        return birthDate;
    }

    Date getFirstbirth() const {
        return firstbirth;
    }

    Date gethundred() const {
        return hundredDate;
    }

    Date getschool() const {
        return school;
    }

    void fun() {
        firstbirth = birthDate;
        if (birthDate.day == 29 && birthDate.month == 2) {
            firstbirth.day = 28;
        }
        firstbirth.year++;
    }

    void fun2() {
        school.year = birthDate.year + 7;
        school.month = 3;
        school.day = 1;
    }

private:
    string name;
    Date birthDate;
    Date hundredDate; // Initialize to birthDate, avoid += 99 here
    Date firstbirth;
    Date school;
};

istream &operator>>(istream &in, Date &d) { // Removed const
    in >> setw(2) >> d.month;
    in.ignore();
    in >> setw(2) >> d.day;
    in.ignore();
    in >> setw(4) >> d.year;
    return in;
}

ostream &operator<<(ostream &output, const Date &d) {
    output << d.month << '/' << d.day << "/" << d.year;
    return output;
}

bool comp(const Baby &b1, const Baby &b2) {
    return b1.getName() < b2.getName();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif
    cout << "Enter the number of newborn babies: ";
    int t;
    cin >> t;
    cin.ignore(100 , '\n');
    vector<Baby> v(t);
    for (int i = 0; i < t; ++i) {
        cout << "\n";
        string s;
        cout << "Enter the baby name: ";
        getline(cin, s);
        v[i].setName(s);
        Date d;
        cout << "Enter the baby's birth date in the form mm/dd/yyyy: ";
        cin >> d;
        v[i].setBirthDate(d);
        cin.ignore(100 , '\n');
        cout << v[i].getName() << " born on " << v[i].getBirthDate() << "\n";
        Date temp = v[i].getBirthDate();
        temp += 99;
        v[i].sethundred(temp);
        cout << "100th day: " << v[i].gethundred() << "\n";
        v[i].fun();
        cout << "First birthday: " << v[i].getFirstbirth() << "\n";
        v[i].fun2();
        cout << "First school day: " << v[i].getschool() << "\n";
    }
    sort(v.begin(), v.end(), comp);
    cout << "\n";
    cout << "Newborn babies in the alphabetical order of names: \n";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].getName() << " (";
        cout << v[i].getBirthDate();
        cout << ")\n";
    }

    return 0;
}
