#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<i64, i64>> p;
    for (int i=0; i<n; ++i) {
        i64 x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }

    ranges::sort(p, [] (auto lhs, auto rhs) {
        if (lhs.first != rhs.first) {
            return lhs.first < rhs.first;
        } else {
            return lhs.second > rhs.second;
        }
    });
    cout << "YES" << endl;
    for (int i=0; i<n-1; ++i) {
        cout << p[i].first << ' ' << p[i].second << endl;
    }

    return 0;
}