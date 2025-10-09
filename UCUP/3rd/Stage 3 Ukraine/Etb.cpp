#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}

#define eb emplace_back

using ll = long long;

template <class T>
T qpow(T x, ll y) {
    T r = 1;
    for (; y; x *= x, y >>= 1) if (y & 1) r *= x;
    return r;
}

template <int mod>
struct ZZ {
    using ref = const ZZ&;
    int v;
    ZZ() : v(0) {}
    ZZ(ll x) : v((x %= mod) < 0 ? x + mod : x) {}
    #define self *this
    #define bop(op, ...) auto operator op##= (ref y) { __VA_ARGS__ return self; } friend auto operator op (ref x, ref y) { return ZZ(x) op##= y; }
    bop(+, v += y.v; if (v >= mod) v -= mod; )
    bop(-, v -= y.v; if (v < 0) v += mod; )
    bop(*, v = ll(v) * y.v % mod; )
    auto inv() const { return pow(mod - 2); }
    #undef bop
    auto pow(ll y) const { return qpow(self, y); }
    #undef self
};

const int mod = 998244353;
using Z = ZZ<mod>;

void sol() {
    int n, m;
    cin >> n >> m;

    vector f(n + 1, vector<Z>(m + 1));
    
    For (i, 1, n) f[i][1] = 1;

    vector<Z> fac(n + 1); 
    fac[0] = 1;
    For (i, 1, n) fac[i] = fac[i - 1] * i;

    auto comb = [&](int n, int m) {
        if (m > n) return Z(0);
        return fac[n] * (fac[m] * fac[n - m]).inv();
    };

    For (j, 2, m) {
        For (i, 1, n) {
            Z S = 0;
            For (k, 1, i) {
                S += comb(i, k) * f[k][j - 1];
            }
            f[i][j] = 2 * Z(j).pow(i) - 1 + S; 
        }
    }

    cout << ((f[n][m] - Z(m).pow(n + 1)) * Z(m + 1).inv() * Z(3).inv() * Z(2).inv()).v << endl;
}