#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i) 

using ll = long long;
using pii = pair<int, int>;
#define fi first 
#define se second

template<class T>
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
    #define bop(op, ...) auto operator op##= (ref r) { __VA_ARGS__ return *this; } friend auto operator op (ref l, ref r) { return ZZ(l) op##= r; }
    bop(+, v += r.v; if (v >= mod) v -= mod; )
    bop(-, v -= r.v; if (v < 0) v += mod; )
    bop(*, v = ll(v) * r.v % mod; )
    auto pow(ll y) const { return qpow(*this, y); }
    auto inv() const { return pow(*this, mod - 2); }
    bop(/, *this *= r.inv(); )
    #undef bop
};

const int mod = 998244353;

using Z = ZZ<mod>;

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) sol();
}

void sol() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> a(n + 1);
    For (i, 1, n) cin >> a[i];

    vector<pii> b(n + 1);
    For (i, 1, n) {
        b[i] = {a[i] % m1, m2 - 1 - a[i] % m2};
    }

    sort(b.begin() + 1, b.end());

    // For (i, 1, n) {
    //     auto [x, y] = b[i];
    //     cout << ' ' << x << ' ' << y << endl;
    // }

    vector<Z> fac(n + 1);
    fac[0] = 1;
    For (i, 1, n) fac[i] = fac[i - 1] * i;
    bool ok = 1;
    Z ans = 1;
    int cnt = 1;
    For (i, 1, n - 1) {
        ok &= b[i].fi <= b[i + 1].fi && b[i].se <= b[i + 1].se;
        if (b[i] != b[i + 1]) {
            ans *= fac[cnt];
            cnt = 1;
        } else {
            ++cnt;
        }
    }

    ans *= fac[cnt];

    if (!ok) {
        cout << 0 << endl;
    } else {
        cout << ans.v << endl;
    }
}