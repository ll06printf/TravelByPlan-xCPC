#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &&ai : a) {
        cin >> ai;
    }
    auto mx = *ranges::max_element(a);
    auto sm = accumulate(a.begin(), a.end(), 0ll);
    cout << sm - mx << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}