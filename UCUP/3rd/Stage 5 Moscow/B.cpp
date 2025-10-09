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

void sol() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    For (i, 1, n) {
        cin >> a[i];
    }

    vector<pii> qu;

    int lst = -2;
    For (i, 1, q) {
        char c;
        cin >> c;
        if (c == 'E') {
            int x, y;
            cin >> x >> y;
            qu.eb(x, y);
        } else {
            lst = (int)qu.size() - 1;
        }
    }

    vector<int> pos(n + 1);
    For (i, 1, n) pos[a[i]] = i;

    int nxt = 0;
    if (lst != -2) {
        For (i, 0, lst) {
            auto [x, y] = qu[i];
            swap(a[pos[x]], a[pos[y]]);
            swap(pos[x], pos[y]);
            // dmp(a);
            // dmp(pos);
        }

        sort(a.begin() + 1, a.begin() + n / 2 + 1, greater<int>());
        sort(a.begin() + n / 2 + 1, a.end());
        For (i, 1, n) pos[a[i]] = i;

        // dmp(a);
        // dmp(pos);

        nxt = lst + 1;
    } else {
        nxt = 0;
    }

    For (i, nxt, (int)qu.size() - 1) {
        auto [x, y] = qu[i];
        swap(a[pos[x]], a[pos[y]]);
        swap(pos[x], pos[y]);
    }

    For (i, 1, n) cout << a[i] << ' ';
    cout << endl;
}