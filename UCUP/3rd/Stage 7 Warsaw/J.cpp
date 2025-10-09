#include <bits/stdc++.h>
using namespace std;

int cost(const string &str) {
    auto n = str.size();
    vector<int> p(n, 0);
    p[0] = str[0] == '1';
    for (int i=1; i<n; ++i) {
        p[i] = p[i-1] + (str[i] == '1');
    }

    auto psum = [&] (int l, int r) {
        auto lv = l == 0 ? 0 : p[l-1];
        auto rv = r == 0 ? 0 : p[r-1];
        return rv - lv;
    };

    int ans = INT_MAX;
    for (int i=0; i<n; ++i) {
        for (int j=i; j<=n; ++j) {
            auto lo = psum(0, i);
            auto ro = psum(j, n);
            auto cz = j - i - psum(i, j);
            ans = min(ans, lo+ro+cz);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    auto ans1 = cost(str);
    cout << ans1 << endl;
}