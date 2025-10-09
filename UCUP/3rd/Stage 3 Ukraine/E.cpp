#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
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

    Z ans = 2 * Z(m).pow(n + 1) + Z(m).pow(n);
    For (i, 1, m) ans -= 2 * Z(i).pow(n);

    cout << ans.v << endl;
}