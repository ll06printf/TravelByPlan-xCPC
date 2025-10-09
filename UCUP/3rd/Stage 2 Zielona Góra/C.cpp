#include <bits/stdc++.h>
#include <climits>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector tb(n, vector<i64>(n));
    for (auto &&rr : tb) {
        for (auto &&ci : rr) {
            cin >> ci;
        }
    }

    if (n == 1) {
        cout << tb[0][0] << endl;
        return ;
    }

    i64 c1, c2, c3;
    i64 c4, c5, c6;
    i64 c7, c8, c9;
    c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = LLONG_MAX;

    auto mid = n / 2;
    
    c5 = min(c5, tb[mid][mid]);
    auto ans1 = c5;

    for (int i=0; i<mid; ++i) {
        c2 = min(c2, tb[i][mid]);
        c4 = min(c4, tb[mid][i]);
        c6 = min(c6, tb[mid][mid+i+1]);
        c8 = min(c8, tb[i+mid+1][mid]);
    }

    for (int i=0; i<mid; ++i) {
        for (int j=0; j<mid; ++j) {
            c1 = min(c1, tb[i][j]);
            c3 = min(c3, tb[i][j+mid+1]);
            c7 = min(c7, tb[i+mid+1][j]);
            c9 = min(c9, tb[i+mid+1][j+mid+1]);
        }
    }

    auto ans2 = min(c4+c6, c2+c8);

    auto ans3 = min({
       c4+c3+c9,
       c2+c7+c9,
       c6+c1+c7,
       c8+c1+c3,

       c4+c2+c9,
       c2+c6+c7,
       c6+c8+c1,
       c8+c4+c3,
    });

    auto ans4 = min({
        c1+c3+c7+c9
    });

    // clog << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << endl;
    cout << min({ans1, ans2, ans3, ans4}) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}