#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define For(i,a,b) for(int i{a};i<=(b);++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i)

template <class T> auto &operator<<(ostream &os, const vector<T> &a) { int n = a.size(); os << '['; For (i, 0, n - 1) { if (i > 0) os << ", "; os << a[i]; } os << ']'; return os; }

#define mtest int T; cin >> T; For(_tid, 0, T - 1)

#ifdef LOCAL
#define dbg if constexpr (1)
#else
#define dbg if constexpr (0)
#endif

#define dmp(x) dbg cout << #x << ": " << x << endl;

template <int mod>
struct ZZ {
    int v;
    using ref = const ZZ&;
    ZZ() : v(0) {}
    ZZ(ll x) : v((x %= mod) < 0 ? x + mod : x) {}

    #define binop(op, ...) auto operator op##= (ref y) { __VA_ARGS__ return *this; } auto operator op (ref y) const { return ZZ(*this) op##= y; }
    binop(+, v += y.v; if (v >= mod) v -= mod; )
    binop(-, v -= y.v; if (v < 0) v += mod; )
    binop(*, v = ll(v) * y.v % mod; )
    auto pow(ll y) const { ZZ r = 1; auto x = *this; for (; y; x *= x, y >>= 1) if (y & 1) r *= x; return r; }
    auto inv() const { return pow(mod - 2); }
    binop(/, *this *= y.inv(); )
    #undef binop

    bool operator==(ref y) const { return v == y.v; }

    friend auto &operator>>(istream &is, ZZ &y) {
        ll x;
        is >> x;
        y = ZZ(x);
        return is;
    }

    friend auto &operator<<(ostream &os, ref y) {
        os << y.v;
        return os;
    }
};

const int mod = 998244353;
using Z = ZZ<mod>;

int _sz = 1;
vector<Z> rt = {1};

template <bool rev = 0>
void dft(vector<Z> &a) {
    int n = a.size();
    if (_sz < n) {
        rt.resize(n);
        while (_sz < n) {
            Z wn = Z(3).pow(mod / 4 / _sz);
            For (i, 0, _sz - 1) rt[i + _sz] = rt[i] * wn;
            _sz <<= 1;
        }
    }

    auto calc = [&](int l) {
        for (auto i = a.begin(), ww = rt.begin(); i != a.end(); i += l << 1, ++ww) {
            for (auto j = i, k = i + l; j != i + l; ++j, ++k) {
                auto &&[u, v, w] = tie(*j, *k, *ww);
                tie(u, v) = rev ? pair(u + v, (u - v) * w) : pair(u + v * w, u - v * w);
            }
        }
    };

    if (!rev) {
        for (int l = n >> 1; l; l >>= 1) calc(l);
    } else {
        for (int l = 1; l < n; l <<= 1) calc(l);
        reverse(a.begin() + 1, a.end());
        Z inv = Z(n).inv();
        for (auto &t : a) t *= inv;
    }
}

auto idft = dft<1>;

#define eb emplace_back

auto qpow(int x, ll y, int p) {
    int r = 1;
    for (; y; x = ll(x) * x % p, y >>= 1) if (y & 1) r = ll(r) * x % p;
    return r;
}

int priroot(int p) {
    int phi = p - 1;
    
    auto frac = [&](int x) {
        vector<int> ps;
        For (i, 2, x) {
            if (x % i == 0) {
                ps.eb(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) ps.eb(x);
        return ps;
    };
    
    auto ps = frac(phi);
    
    For (i, 1, p - 1) {
        bool ok = 1;
        for (auto cp : ps) {
            ok &= qpow(i, phi / cp, p) != 1;
        }
        if (ok) return i;
    }
    
    cout << "Err " << endl;
    
    return -1;
}

auto conv(vector<Z> &f, vector<Z> g) {
    assert(f.size() == g.size());
    int n = f.size();
    int sz = __bit_ceil(2 * n + 1);
    f.resize(sz);
    g.resize(sz);
    dft(f);
    dft(g);
    
    For (i, 0, sz - 1) {
        f[i] *= g[i];
    }

    idft(f);
    For (i, n, sz - 1) {
        f[i % n] += f[i];
    }

    f.resize(n);
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> idx;
    auto calcw = [&](int p) {
        vector C(p, vector<int>(p));
        C[0][0] = 1;
        vector<Z> w(p);
        For (i, 1, p - 1) {
            C[i][0] = 1;
            For (j, 1, p - 1) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
            }
        }
    
        For (i, 0, p - 1) For (j, 0, p - 1) {
            w[C[i][j]] += 1;
        }

        w[0] = 0;
    
        int g = priroot(p);
    
        For (i, 0, p - 2) {
            idx[qpow(g, i, p)] = i;
        }
    
        vector<Z> w2(p - 1);
        For (i, 1, p - 1) {
            w2[idx[i]] = w[i];
        }
        return w2;
    };

    string sk;
    int p, x;
    cin >> sk >> p >> x;

    idx.resize(p);
    auto f = calcw(p);
    
    vector<Z> g(p - 1);
    g[0] = 1;

    int nk = sk.size();
    Dor (i, nk - 1, 0) {
        char c = sk[i];
        if (c == '1') {
            conv(g, f);
        }

        conv(f, f);
    }

    cout << g[idx[x]] << endl;
}