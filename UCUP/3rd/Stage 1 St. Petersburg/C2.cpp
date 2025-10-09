#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct uf_set {
    vector<int> p;
    vector<int> sz;
    multiset<int, greater<>> sz_st;

    uf_set(int n)
        : p(n)
        , sz(n, 1)
    {
        iota(p.begin(), p.end(), 0);
        for (int i=0; i<n; ++i) {
            sz_st.insert(1);
        }
    }

    int top(int x) {
        while (p[x] != x) {
            x = p[x] = p[p[x]];
        }
        return x;
    }
    void move_one(int sz) {
        auto iter = sz_st.find(sz);
        assert(iter != sz_st.end());
        sz_st.erase(iter);
    }
    void merge(int lhs, int rhs) {
        auto tl = top(lhs);
        auto tr = top(rhs);
        if (tl != tr) {
            p[tr] = tl;
            move_one(sz[tl]);
            move_one(sz[tr]);
            sz[tl] += sz[tr];
            sz_st.insert(sz[tl]);
        }
    }
    int tree_sz(int x) {
        return sz[top(x)];
    }
    void desc(int x) {
        auto &&ss = sz[top(x)];
        move_one(ss);
        sz_st.insert(--ss);
    }
    int mx_sz() {
        return *sz_st.begin();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int mx_rk = 100'000;

    int n, k;
    cin >> n >> k;

    vector<int> rk(n);
    for (auto &&ri : rk) {
        cin >> ri;
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, less{}, [&](int i) {
        return rk[i];
    });

    string ww;
    cin >> ww;

    uf_set us(n);
    for (int i=0; i<n; ++i) {
        if (ww[i] == '0') {
            us.desc(i);
        }
    }

    for (int i=1; i<n; ++i) {
        if (ww[i] == '1' && ww[i-1] == '1') {
            us.merge(i-1, i);
        }
    }

    int ans = 0;

    if (us.mx_sz() >= k) {
        ans = rk[id[0]];
    }

    set<int> rem_idx;
    for (int i=0; i<n; ++i) {
        rem_idx.insert(i);
    }

    for (int i=0; i<n; ++i) {
        auto idx = id[i];
        auto cur_rk = rk[idx];

        if (ww[idx] == '0') {
            rem_idx.erase(idx);
            auto iter = rem_idx.upper_bound(idx);
            if (iter != rem_idx.end() && iter != rem_idx.begin()) {
                auto liter = prev(iter);
                assert(*iter > idx);
                assert(*liter < idx);
                if (ww[*iter] == '1' && ww[*liter] == '1') {
                    us.merge(*liter, *iter);
                }
            }
        } else {
            assert(ww[idx] == '1');
            rem_idx.erase(idx);
            us.desc(idx);
        }

        if (i != n-1 && cur_rk != rk[id[i+1]]) {
            auto nxt_rk = rk[id[i+1]];
            if (us.mx_sz() >= k) {
                ans = nxt_rk;
            }
        }
    }

    cout << ans << endl;

}