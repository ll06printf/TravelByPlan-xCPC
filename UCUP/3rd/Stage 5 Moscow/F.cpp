// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i) 

using ll = long long;
using pii = pair<int, int>;
#define fi first 
#define se second
#define eb emplace_back

#define dmp(x) cout << #x << ": " << x << endl;

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

template <class U, class V>
ostream &operator<<(ostream &os, const pair<U, V> &v) {
    os << '(' << v.fi << ", " << v.se << ')';
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T>& a) {
    int n = a.size();
    os << '[';
    For (i, 0, n - 1) {
        if (i > 0) os << ", ";
        os << a[i];
    }
    os << ']';
    return os;
}

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

mt19937_64 gen;
int rnd(int l, int r) {
    uniform_int_distribution<int> rnd(l, r);
    return rnd(gen);
}

template <class T>
void cmax(T &x, T y) {
    if (y > x) x = y;
}

template <class T>
void cmin(T &x, T y) {
    if (y < x) x = y;
}

void sol() {
    int n;
    cin >> n;

    vector<int> c(n + 1);
    For (i, 1, n) cin >> c[i];

    const ll inf = LONG_LONG_MAX / 3;
    vector f(n + 1, vector<ll>(n + 1, inf));

    For (i, 1, n) f[i][i] = 0;

    For (len, 2, n) {
        vector e(n + 1, vector<pair<int, ll>>());
        For (l, 1, n - len + 1) {
            int r = l + len - 1;
            For (k, 1, n) {
                int fl = 2 * k - r, fr = 2 * k - l;
                
                auto calc = [&](int fl ,int fr) -> ll {
                    tie(fl, fr) = pair{2 * k - fr, 2 * k - fl};
                    return f[fl][fr];
                };
                
                if (1 <= fl) {
                    if (fr <= n) {
                        // cmin(f[l][r], f[fl][fr] + c[k]);
                        e[l].eb(fl, c[k]);
                    } else {
                        if (fl <= n) {
                            // [fl, n] [n + 1, fr]
                            cmin(f[l][r], max(f[fl][n], calc(n + 1, fr)) + c[k]);
                        }
                    }
                } else {
                    if (fr >= 1) {
                        // [fl, 0] [1, fr]
                        cmin(f[l][r], max(calc(fl, 0), f[1][fr]) + c[k]);
                    }
                }
            }
        }

        vector<ll> dist(n + 1, inf);
        dist[0] = 0;
        For (l, 1, n - len + 1) e[0].eb(l, f[l][l + len - 1]);

        vector<bool> vis(n + 1);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, 0);
        vis[0] = 1;
        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du > dist[u]) continue;
            vis[u] = 1;
            
            for (auto [v, w] : e[u]) {
                if (vis[v]) continue;
                if (dist[v] > min(inf, dist[u] + w)) {
                    dist[v] = min(inf, dist[u] + w);
                    pq.emplace(dist[v], v);
                }
            }
        }

        For (l, 1, n - len + 1) cmin(f[l][l + len - 1], dist[l]);
    }

    // For (i, 1, n) {
    //     For (j, 1, n) {
    //         cout << i << ' '  << j << ' ' << f[i][j] << endl;
    //     }
    // }

    cout << f[1][n] << endl;
}