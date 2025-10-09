#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;

    auto pos_i = [&] (int i, int t) {
        return 2 * (i-1) + t + 1;
    };
    auto sc_i = [] (int i) {
        return 1 + (i % 2 == 0);
    };

    auto n = k + 2;

    vector<pair<int, int>> eg;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<i; ++j) {
            eg.push_back({pos_i(j, 0), pos_i(i, 1)});
            eg.push_back({pos_i(j, 1), pos_i(i, 0)});
        }
    }

    cout << n*2 << ' ' << eg.size() << ' ' << 2 << endl;
    for (int i=1; i<=2*n; ++i) {
        cout << sc_i(i) << ' ';
    }
    cout << endl;
    for (auto [u, v] : eg) {
        assert(u <= 2 * n && v <= 2 * n);
        assert(sc_i(u) != sc_i(v));
        cout << u << ' ' << v << endl;
    }
}