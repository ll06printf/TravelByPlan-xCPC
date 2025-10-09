#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iomanip>
#include <limits>
#include <ostream>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define For(i,a,b) for(int i =(a);i<=(b);++i)
#define Dor(i,a,b) for(int i =(a);i>=(b);--i)

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

const int mod = 1e9 + 7;

int mul(int x, int y) {
    return ll(x) * y % mod;
}

int add(int x, int y) {
    int r = x + y;
    if (r >= mod) r -= mod;
    return r;
}

int qpow(int x, ll y) {
    int r = 1;
    for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
    return r;
}

using lf = long double;

#define eb emplace_back

template <class T>
ostream &operator<<(ostream &os, const vector<T>& v) {
    os << '[';
    For (i, 0, v.size() - 1) {
        if (i > 0) os << ", ";
        os << v[i];
    }
    os << ']';
    return os;
}

void sol() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    int V = 0;
    vector<int> S(n + 1);
    For (i, 1, n) {
        cin >> a[i];
        S[i] = S[i - 1] + a[i];
        V = max(V, a[i]);
    }

    auto chk = [&](lf x) -> int {
        vector<lf> a(n + 1);
        For (i, 0, n) a[i] = S[i] - i * x;

        if (a[0] > a[n]) {
            return -1;
        }

        const lf inf = numeric_limits<lf>::max() / 3;

        vector<lf> v = {a[0]};
        For (i, 1, n - 1) {
            if (a[i] < a[0]) continue;
            int len = upper_bound(v.begin(), v.end(), a[i]) - v.begin() - 1;
            // cout << v << ' ' << a[i] << ' ' <<len << endl;
            if (len + 1 < v.size()) v[len + 1] = fminl(v[len + 1], a[i]);
            else v.eb(a[i]);
        }

        int len = upper_bound(v.begin(), v.end(), a[n]) - v.begin();

        // vector<int> f(n + 1, -INT_MAX / 3);
        // vector<int> lst(n + 1);
        // f[0] = 0;
        // For (i, 1, n) {
        //     For (j, 0, i - 1) {
        //         if (a[i] >= a[j]) {
        //             if (f[j] + 1 > f[i]) {
        //                 lst[i] = j;
        //             }
        //             f[i] = max(f[j] + 1, f[i]);
        //         }
        //     }
        // }

        // if (len != f[n]) {
        //     cout << "Err " << len << ' ' << f[n] << endl;
        //     cout << a << endl;
        //     int p = n;
        //     vector<lf> t;
        //     while (p) {
        //         t.eb(a[p]);
        //         p = lst[p];
        //     }
        //     cout << t << endl;
        //     cout << v << endl;
        // }

        return len;
    };

    lf l = 0, r = V;
    For (tt, 1, 100) {
        lf mid = (l + r) / 2;
        if (chk(mid) >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(13) << l << endl;
}