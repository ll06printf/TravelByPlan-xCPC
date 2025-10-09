#include <algorithm>
#include <bits/stdc++.h>
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

using pii = pair<int, int>;
#define fi first 
#define se second

const int V = 2e7;
using bs = bitset<V>;
bs f;
int sol2(int n, vector<int> &a) {
    sort(a.begin(), a.end());
    int m = a[n];

    auto b = a;
    int mi = INT_MAX;
    for (auto &t : b) t -= m, mi = min(mi, t);

    For (i, 0, 2 * n - 1) {
        if (b[i] - mi != 0) f |= (f << (b[i] - mi));
    }

    return f[-mi];
}

ll sol() {
    int n = 50, V = 1e9;
    auto x = gsum(n, V);
    auto y = gsum(n, V);
    
    vector<int> z(2 * n);
    For (i, 0, n - 1) z[i] = x[i];
    For (i, n, 2 * n - 1) z[i] = y[i - n];
    
    shuffle(z.begin(), z.end(), gen);

    // if (!sol2(n, z)) {
    //     cout << "Err " << endl;
    // }

    return abs(z[0]-V/n);

    return 0;
}

int main() {
    int T;
    cin >> T;
    ll S = 0;
    for (int i = 1; i <= T; ++i) {
        S += sol();
    }

    cout << S / T << endl;
}