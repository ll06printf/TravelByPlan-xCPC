#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define For(i,a,b) for(int i{a};i<=(b);++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i)

template <class U, class V> auto &operator<<(ostream &os, const pair<U, V> &v) { os << '(' << v.first << ", " << v.second << ')'; return os; }
template <class T> auto &operator<<(ostream &os, const vector<T> &a) { int n = a.size(); os << '['; For (i, 0, n - 1) { if (i > 0) os << ", "; os << a[i]; } os << ']'; return os; }

#define mtest int T; cin >> T; For(_tid, 0, T - 1)

#if defined(LOCAL) and not defined(ONLINE_JUDGE)
#define dbg if constexpr (1)
#else
#define dbg if constexpr (0)
#endif

#define eb emplace_back
#define dmp(x) dbg cout << #x << ": " << x << endl;

struct sgt_t {
    int n;
    vector<int> a;

    sgt_t(int n) : n(n), a(n << 2 | 1, -1) {}

    #define lc (u << 1)
    #define rc (u << 1 | 1)

    void modi(int qx, int v) {
        auto rec = [&](auto &&rec, int u, int l, int r) -> void {
            if (l == r) {
                a[u] = v;
                return;
            }

            int m = (l + r) >> 1;
            if (qx <= m) rec(rec, lc, l, m);
            else rec(rec, rc, m + 1, r);
            a[u] = max(a[lc], a[rc]);
        };
        rec(rec, 1, 1, n);
    }

    int qu(int x) {
        int ans = -1;
        auto rec = [&](auto &&rec, int u, int l, int r) -> void {
            // dbg cout << "qu " <<  u << ' ' << l << ' ' << r << endl;
            if (l == r) {
                if (a[u] >= x) {
                    ans = l;
                }
                return;
            }

            int m = (l + r) >> 1;
            if (a[rc] >= x) {
                rec(rec, rc, m + 1, r);
            } else {
                rec(rec, lc, l, m);
            }
        };
        rec(rec, 1, 1, n);
        return ans;
    }

    auto get() {
        vector<int> ret;
        auto rec = [&](auto &&rec, int u, int l, int r) -> void {
            if (l == r) {
                ret.eb(a[u]);
                return;
            }

            int m = (l + r) >> 1;
            rec(rec, lc, l, m);
            rec(rec, rc, m + 1, r);
        };
        rec(rec, 1, 1, n);
        return ret;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    int V = 0;
    For (i, 0, n - 1) cin >> a[i], V = max(V, a[i]);

    vector qu(n, vector<pii>());
    For (i, 0, q - 1) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        qu[r].eb(l, i);
    }

    auto frac = [&](int x) {
        vector<int> d;
        for (int i = 1; i <= x / i; ++i) {
            if (x % i == 0) {
                d.eb(i);
                if (i * i != x) d.eb(x / i);
            }
        }
        return d;
    };

    vector stks(V + 1, vector<pii>());
    vector vals(V + 1, vector<int>());

    sgt_t sgt(V);

    vector<int> ans(q);
    For (i, 0, n - 1) {
        auto ds = frac(a[i]);
    
        // dmp(i);

        // dmp(ds);

        // sort(ds.begin(), ds.end());

        for (auto d : ds) {
            // dmp(i);
            // dmp(d);

            auto &stk = stks[d];
            auto &val = vals[d];

            // dmp(stk);
            // dmp(val);

            int nv;
            auto it = upper_bound(stk.begin(), stk.end(), pii{i, n + 1});
            if (it == stk.begin()) {
                nv = -1;
            } else {
                nv = prev(it)->second;
            }

            if (val.size()) {
                int ns = 2 * i - val.back();

                while (!stk.empty() && stk.back().first > ns) stk.pop_back();
                stk.eb(ns, val.back());
            }

            val.eb(i);

            // dmp(stk);
            // dmp(val);
            // dmp(nv);

            // dbg {
            //     if (i == 5 && d == 3) {
            //         dmp(stk);
            //         dmp(val);
            //     }
            // }

            // dbg cout << "upd " << d << ' ' << nv << endl;

            if (nv != -1) sgt.modi(d, nv);
        }

        // dmp(i);
        // dmp(sgt.get());

        for (auto [l, id] : qu[i]) {
            int ret = sgt.qu(l);
            // dmp(l);
            // dmp(ret);
            ans[id] = ret == -1 ? 0 : ret;

            // dbg cout << id << ": " << ans[id] << ' ' << l << ' ' << i << endl;
        }
    }

    For (i, 0, q - 1) {
        cout << ans[i] << endl;
    }
}