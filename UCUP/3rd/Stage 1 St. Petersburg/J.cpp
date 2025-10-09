#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <climits>
#include <iomanip>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using lf = long double;

mt19937_64 gen;
int rnd(int l, int r) {
    uniform_int_distribution<int> rnd(l, r);
    return rnd(gen);
}

#define eb emplace_back

vector<int> gsum(int n, int s) {
    vector<int> a(n + 1);
    For (i, 1, n - 1) {
        a[i] = rnd(1, s);
    }
    a[n] = s;

    sort(a.begin() + 1, a.end());

    vector<int> ret;

    For (i, 1, n) {
        ret.eb(a[i] - a[i - 1]);
    }

    return ret;
}

int sol1(int n, vector<int> &a) {
    For (i, 1, n) {
        for (int j = 0; j < (1 << n); ++j) {
            for (auto t : ) {

            }
        }
    }
}

int sol2(int n, vector<int> &a) {
    sort(a.begin(), a.end());
    int m = a[n / 2];

    auto b = a;
    int mi = INT_MAX;
    for (auto &t : b) t -= m, mi = min(mi, t);

    const int V = 1e8;
    using bs = bitset<V>;
    bs f;
    For (i, 0, 2 * n - 1) {
        f = f | (f << (b[i] + mi));
    }

    return f[mi];
}

int main() {
    int T;
    cin >> T;
    ll S = 0;
    for (int i = 1; i <= T; ++i) {
        S += sol();
    }

    cout << S / T * 100 / 64 << endl;
}