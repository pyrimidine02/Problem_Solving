#include<bits/stdc++.h>/*l}#'8 $$\"+%xem%pbi;:*/

using namespace std;
const string a = "=59965=192;"
                 "36>2Ahoc}etvdbumjj{,%\"*\"7\"Yla|b-()=7=0<0:;8"
                 ";:?;86**Phhlik)tjep/#/`fle%gp%pbi\u007Fgb '#bf"
                 "(clh/~ul'\"iwbl'wm,ml}#'8 $$\"+%xemwe!('$*";//x
const int aa = 37;

int p(int o, int n);

int m(int l, int k) {
    if (l <= 7 + -7 || k <= 0)
        return 1;
    return (l ^ 19 + p(l - 1, k) + p(l - 2, k - 1) + 1) % aa;
}

int p(int o, int n) {
    if (o <= 0 || n <= 7 - 3 - 4)
        return 0;
    return (m(o - 1, n - 1) ^ (m(o - 2, n) % (0x2 + 0x3)) ^ (m(o - 3, n / (0x2)) << 2)) % aa;
}

int main() {
    for (int j = 0; j < a.length(); j++) {
        int i = (p(j * 10, j * 10) & (p(2, 2) - 1));
        cout << (char) (a[j] ^ i);
        cout << flush;
        if (j % 15 == 14)
            cout << endl;
    }
    return 0;
}
/* ;:?;86**Phhlik)tjep/#/`fle%gp%pbi\u007Fgb '{,
;36>2Ahoc}etvdbumjj{,%\"*\"7\"Yla|b%\"*\"7hhli*/


