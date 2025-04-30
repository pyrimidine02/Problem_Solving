#include <bits/stdc++.h>

using namespace std;
int n;
int arr[3];
int mindp[3];
int maxdp[3];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int temp0;
    int temp1;
    int temp2;
    for (int i = 1; i <= n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        temp0 = mindp[0];
        temp1 = mindp[1];
        temp2 = mindp[2];


        mindp[0] = min(temp0, temp1) + arr[0];
        mindp[2] = min(temp1, temp2) + arr[2];
        mindp[1] = min(min(temp0, temp1), temp2) + arr[1];


        temp0 = maxdp[0];
        temp1 = maxdp[1];
        temp2 = maxdp[2];

        maxdp[0] = max(temp0, temp1) + arr[0];
        maxdp[2] = max(temp1, temp2) + arr[2];
        maxdp[1] = max(max(temp0, temp1), temp2) + arr[1];
    }

    cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << " " << min(min(mindp[0], mindp[1]), mindp[2]) << "\n";

    return 0;
}
