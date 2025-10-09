#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    i64 n;
    cin >> n;
    if (n < 10) {
        cout << n + 1 << endl;
    } else {
        cout << 10 << endl;
    }

    return 0;
}