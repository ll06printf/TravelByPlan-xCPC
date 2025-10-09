#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct seg {
    i64 l;
    i64 r;
    bool free_l;
    bool free_r;

    friend bool interact(const seg &lhs, const seg &rhs) {
        auto ml = max(lhs.l, rhs.l);
        auto mr = min(lhs.r, rhs.r);
        return ml <= mr;
    }
};

void solve() {

    #define fail_ans {cout << "NIE" << endl; return ;}
    #define scc_ans {cout << "TAK" << endl; return ;}

    i64 n, l;
    cin >> n >> l;
    i64 free_cnt = 0;

    vector<seg> s;
    for (int i=0; i<n; ++i) {
        i64 l, r;
        cin >> l >> r;
        if (l == -1 && r == -1) {
            free_cnt++;
        } else {
            if (l == -1) {
                s.push_back({r, r, true, false});
            } else if (r == -1) {
                s.push_back({l, l, false, true});
            } else {
                s.push_back({l, r, false, false});
            }
        }
    }

    if (n > l) fail_ans;

    ranges::sort(s, [&] (auto &&lhs, auto &&rhs) -> bool {
        if (lhs.l != rhs.l) {
            return lhs.l < rhs.l;
        } else {
            return lhs.r < rhs.r;
        }
    });

    if (s.empty()) {
        assert(free_cnt > 0);
        if (free_cnt <= l)
            scc_ans
        else 
            fail_ans
    }

    for (int i=0; i+1<s.size(); ++i) {
        if (interact(s[i], s[i+1]))
            fail_ans
    }

    i64 req_free_cnt = 0;
    i64 max_free_pos = 0;
    if (s.front().l != 1) {
        if (! s.front().free_l) {
            req_free_cnt++;
        }
        max_free_pos += s.front().l - 1;
    }
    for (int i=0; i+1<s.size(); ++i) {
        if (s[i].r+1 != s[i+1].l) {
            if (! s[i].free_r && ! s[i+1].free_l) {
                req_free_cnt++;
            }
            max_free_pos += s[i+1].l - s[i].r - 1;
        }
    }
    if (s.back().r != l) {
        if (! s.back().free_r) {
            req_free_cnt++;
        }
        max_free_pos += l - s.back().r;
    }

    if (req_free_cnt <= free_cnt && free_cnt <= max_free_pos)
        scc_ans
    else 
        fail_ans
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}