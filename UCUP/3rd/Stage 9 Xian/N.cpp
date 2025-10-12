#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

tuple<i64, i64, i64> get_stmt() {
    char ch;
    cin >> ch;
    while (ch != '(') {
        cin >> ch;
    }
    i64 a, b, c;
    if (isalpha(cin.peek())) {
        a = LLONG_MAX;
        cin >> ch;
    } else {
        cin >> a;
    }
    cin >> ch;
    if (isalpha(cin.peek())) {
        b = LLONG_MAX;
        cin >> ch;
    } else {
        cin >> b;
    }
    if (cin.peek() == ',') {
        cin >> ch;
        if (isalpha(cin.peek())) {
            c = LLONG_MAX;
            cin >> ch;
        } else {
            cin >> c;
        }
    } else {
        c = 1;
    }
    return {a, b, c};
}

void loop(i64 a, i64 b, i64 c, auto &&f) {
    if ((a < b) != (c > 0)) {
        return ;
    }

    if (a < b) {
        for (i64 i = a; i < b; i+=c) {
            f(i);
        }
    } else {
        for (i64 i = a; i > b; i+=c) {
            f(i);
        }
    }
}

i64 delta(i64 a, i64 b, i64 c) {
    if ((a < b) != (c > 0)) {
        return 0;
    }
    auto t = 1 + (abs(b - a) - 1) / abs(c);
    return a * t + t * (t-1) / 2 * c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin.ignore();
    auto [a, b, c] = get_stmt();
    auto [d, e, f] = get_stmt();
    cin.ignore();
    cin.ignore();

    i64 ans = 0;
    loop(a, b, c, [&] (i64 i) {
        i64 nd = d;
        i64 ne = e;
        i64 nf = f;
        if (d == LLONG_MAX) {
            nd = i;
        }
        if (e == LLONG_MAX) {
            ne = i;
        }
        if (f == LLONG_MAX) {
            nf = i;
        }
        auto cd = delta(nd, ne, nf);
        // cout << nd << ' ' << ne << ' ' << nf << ' ' << cd << endl;
        ans += delta(nd, ne, nf);
    });
    cout << ans << endl;
}