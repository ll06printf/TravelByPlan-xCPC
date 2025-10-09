#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto &&ai : a) {
        cin >> ai;
    }

    vector<i64> sel(a.begin(), a.end());
    for (int i=n-1; i >= 0; --i) {
        auto pi = i + k;
        if (pi < n) {
            sel[i] = max(sel[pi], sel[i]);
        }
    }

    vector<i64> ans;
    for (int i=0; i<n; ) {
        if (a[i] == sel[i]) {
            ans.push_back(a[i]);
            i++;
        } else {
            i += k;
        }
    }

    for (auto aa : ans) {
        cout << aa << ' ';
    }
    cout << endl;

    return 0;

}