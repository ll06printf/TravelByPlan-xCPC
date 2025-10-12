#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define For(i,a,b) for(int i{a};i<=(b);++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i)

#define eb emplace_back

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
};

const int N = 150000;
const int VV = 1e6;
int a[N];

vector<pii> stks[VV + 1];
vector<int> vals[VV + 1];

vector<pii> qu[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;

    int V = 0;
    For (i, 0, n - 1) cin >> a[i], V = max(V, a[i]);

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

    // vector stks(V + 1, vector<pii>());
    // vector vals(V + 1, vector<int>());

    sgt_t sgt(V);

    vector<int> ans(q);
    For (i, 0, n - 1) {
        auto ds = frac(a[i]);

        for (auto d : ds) {
            auto &stk = stks[d];
            auto &val = vals[d];

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

            if (nv != -1) sgt.modi(d, nv);
        }

        for (auto [l, id] : qu[i]) {
            int ret = sgt.qu(l);
            ans[id] = ret == -1 ? 0 : ret;
        }
    }

    For (i, 0, q - 1) {
        cout << ans[i] << endl;
    }
}