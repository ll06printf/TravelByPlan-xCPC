#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 up_div(i64 x, i64 m) {
    return (x + m -1) / m;
}

void solve() {
    i64 w, h, s;
    cin >> w >> h >> s;
    if (w < h) {
        swap(w, h);
    }

    auto p1 = w / s;
    auto r1 = w % s;
    auto p2 = h / s;
    auto r2 = h % s;

    i64 ans = 0;
    if (p1 == 0 && p2 == 0) {
        if (w + h == s) {
            ans = 2;
        } else if (
            2 * h == s
            || 2 * w == s
            || 2 * s == 2 * h + w 
            || 2 * s == 2 * w + h 
            || 3 * s == 2 * w + 2 * h
        ) 
            ans = 3;
        else {
            ans = 4;
        }
    } else if (p1 == 1 && p2 == 0) {
        if (2 * h + w >= 2 * s) {
            ans = up_div(2*(w + h), s);
        } else if (2 * (w + h) == 3 * s) {
            ans = 3;
        } else {
            ans = 4;
        }
    } else {
        // ans = 2 * (p1 + p2) + up_div(2*(r1+r2), s);
        ans = up_div(2*(w+h), s);
    }
    cout << ans << endl;
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