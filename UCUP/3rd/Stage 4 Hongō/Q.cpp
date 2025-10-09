#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &&ai : a) {
        cin >> ai;
    }
    ranges::sort(a, greater<>{});

    vector<i64> pa;
    vector<bool> mov(n, false);
    for (int i=2; i<n; ++i) {
        if (a[i] != a[i-1]) {
            mov[i-1] = true;
        }
    }
    for (int i=0; i<n; ++i) {
        if (! mov[i]) {
            pa.push_back(a[i]);
        }
    }
    for (int i=n-1; i>=0; --i) {
        if (mov[i]) {
            pa.push_back(a[i]);
        }
    }
    i64 ans = 0;
    for (int i=0; i<n; ++i) {
        auto ni = (i + 1) % n;
        ans += a[ni] / a[i];
    }
    cout << ans << endl;
}