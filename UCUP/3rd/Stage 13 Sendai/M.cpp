#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using pii = pair<int, int>;
#define eb emplace_back
#define fi first 
#define se second
using i64 = long long;

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

template <int mod>
struct ZZ {
    using ref = const ZZ &;
    int v;
    ZZ() : v(0) {}
    ZZ(ll x) : v((x %= mod) < 0 ? x += mod : x) {}
    #define bop(op, ...) auto operator op##= (ref r) { __VA_ARGS__; return *this; } friend auto operator op (ref l, ref r) { return ZZ(l) op##= r; }
    bop(+, v += r.v; if (v >= mod) v -= mod; );
    bop(-, v -= r.v; if (v < 0) v += mod; );
    bop(*, v = ll(v) * r.v % mod; );
    #undef bop
};

const int mod = 998244353;
using Z = ZZ<mod>;

struct mat {
    int n;
    vector<Z> v;
    using ref = const mat &;

    mat(int _n) : n(_n), v(n * n) {}
    
    Z &operator[](pair<int, int> id) {
        return v[id.fi * n + id.se];
    }

    Z operator[](pair<int, int> id) const {
        return v[id.fi * n + id.se];
    }
    
    friend mat operator*(const mat &a, const mat &b) {
        assert(a.n == b.n);
        int n = a.n;
        mat c(n);
        For (i, 0, n - 1) {
            For (k, 0, n - 1) {
                Z aik = a[{i, k}];
                For (j, 0, n - 1) {
                    c[{i, j}] += aik * b[{k, j}];
                }
            }
        }
        return c;
    }

    mat &operator*=(const mat &b) {
        *this = *this * b;
        return *this;
    }

    #define bop(op, ...) auto operator op##= (ref r) { __VA_ARGS__; return *this; } friend auto operator op (ref l, ref r) { return mat(l) op##= r; }
    bop(+, For (i, 0, n - 1) For (j, 0, n - 1) (*this)[{i, j}] += r[{i, j}]; );
    bop(-, For (i, 0, n - 1) For (j, 0, n - 1) (*this)[{i, j}] -= r[{i, j}]; );
    #undef bop

    friend ostream &operator<<(ostream &os, ref r) {
        int n = r.n;
        For (i, 0, n - 1) {
            For (j, 0, n - 1) {
                os << r[{i, j}].v << ' ';
            }
            os << endl;
        } 
        return os;
    }

    static mat id(int n) {
        mat r(n);
        For (i, 0, n - 1) r[{i, i}] = 1;
        return r;
    }

    mat() : n(-1) {}
};

mat qpow(mat x, ll y) {
    int n = x.n;
    mat r = mat::id(n);

    for (; y; x *= x, y >>= 1) if (y & 1) r *= x;
    return r;
}



void sol() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    const mat I = mat::id(n);

    mat M(n);

    vector<int> deg(n);
    For (i, 1, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        M[{u, v}] = M[{v, u}] = 1;
        ++deg[u], ++deg[v];
    }

    mat D(n);
    For (i, 0, n - 1) D[{i, i}] = deg[i];

    vector<mat> f(3);

    auto f0 = mat::id(n);
    auto f1 = M;
    auto f2 = M * f1 - f0 * D;
    
    f[0] = f0, f[1] = f1, f[2] = f2;

    if (k <= 2) {
        cout << f[k][{0, n - 1}].v << endl;
        return; 
    }

    mat P(2 * n);
    For (i, 0, n - 1) For (j, 0, n - 1) {
        P[{i, j}] = M[{i, j}];
    }

    For (i, n, 2 * n - 1) For (j, 0, n - 1) {
        P[{i, j}] = I[{i - n, j}];
    }

    auto B = I - D;
    For (i, 0, n - 1) For (j, n, 2 * n - 1) {
        P[{i, j}] = B[{i, j - n}];
    }

    auto Pk = qpow(P, k - 2);

    mat ans;
    {
        mat A(n), B(n);
        For (i, 0, n - 1) For (j, 0, n - 1) A[{i, j}] = Pk[{i, j}];
        For (i, 0, n - 1) For (j, n, 2 * n - 1) B[{i, j - n}] = Pk[{i, j}];
    
        ans = A * f2 + B * f1;
    }

    cout << ans[{0, n - 1}].v << endl;
}