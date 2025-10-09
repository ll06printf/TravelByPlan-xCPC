#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<multiset<int>> rv(n);
    vector<multiset<int, greater<void>>> cv(n);
    vector<vector<int>> gd(n, vector<int>(n));
    for (auto &&ri : gd) {
        for (auto &&ai : ri) {
            cin >> ai;
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            rv[i].insert(gd[i][j]);
            cv[j].insert(gd[i][j]);
        }
    }

    auto remove_ele = [&] (int i, int j, int e) {
        auto ri = rv[i].find(e);
        auto ci = cv[j].find(e);
        assert(ri != rv[i].end() && ci != cv[j].end());
        rv[i].erase(ri);
        cv[j].erase(ci);
    };

    vector<bool> remove_r(n, false);
    vector<bool> remove_c(n, false);
    auto sel = [&] (auto &&g, auto cmp, auto &&efg) -> int {
        auto c2 = [&] (auto &&lhs, auto &&rhs) {
            auto li = lhs.begin();
            auto ri = rhs.begin();
            while (li != lhs.end() && ri != rhs.end() && *li == *ri) {
                ++li;
                ++ri;
            }
            if (li == lhs.end()) {
                return false;
            } else {
                assert(ri != lhs.end());
                return cmp(*li, *ri);
            }
        };

        int mi;
        for (int i=0; i<n; ++i) {
            if (! efg[i]) {
                mi = i;
                break;
            }
        }
        for (int i=mi+1; i<n; ++i) {
            if (! efg[i] && c2(g[i], g[mi])) {
                mi = i;
            }
        }
        return mi;
    };

    for (int i=0; i<2 * n - 2; ++i) {
        if (i % 2 == 0) {
            auto rri = sel(rv, less<void>{}, remove_r);
            for (int ci = 0; ci < n; ++ci) {
                if (remove_c[ci]) {
                    continue;
                }
                remove_ele(rri, ci, gd[rri][ci]);
            }
            remove_r[rri] = true;
        } else {
            auto cci = sel(cv, greater<void>{}, remove_c);
            for (int ri = 0; ri < n; ++ri) {
                if (remove_r[ri]) {
                    continue;
                }
                remove_ele(ri, cci, gd[ri][cci]);
            }
            remove_c[cci] = true;
        }
    }
    for (int i = 0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (! remove_r[i] && ! remove_c[j]) {
                cout << gd[i][j] << endl;
            }
        }
    }
}