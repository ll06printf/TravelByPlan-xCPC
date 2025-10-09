#include <bits/stdc++.h>
using namespace std;

constexpr int dt = 24*60;
const auto half_t = 12 * 60;
constexpr int lst_tm = 24*60 - 1;

int sel_tm;
int ct = 0;

bool query(int t, int i) {
    assert(++ct <= 50);
    auto hh = t / 60;
    auto mm = t % 60;
    cout << format("at {:02}:{:02} check {}", hh, mm, i+1) << endl;
    // string ans;
    // cin >> ans;
    // return ans == "awake";

    if (sel_tm <= half_t) {
        return ! (sel_tm <= t && t < sel_tm + half_t);
    } else {
        auto ss = sel_tm - half_t;
        return ss <= t && t < ss + half_t;
    }

}

void answer(const vector<int> &ans) {
    cout << "answer" << endl;
    for (auto tt : ans) {
        auto hh = tt / 60;
        auto mm = tt % 60;
        cout << format("{:02}:{:02}", hh, mm) << endl;
    }
    assert(ans.front() == sel_tm);
}

struct evt {
    int tt;
    int st;
    int i;
    int d;
    friend bool operator< (const evt &lhs, const evt &rhs) {
        return lhs.tt > rhs.tt;
    }
};

void sol(int n) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    // int n;
    // cin >> n;

    vector<int> ans(n);
    priority_queue<evt> que;
    vector<bool> first_st(n);
    for (int i=0; i<n; ++i) {
        first_st[i] = query(0, i);
        que.push({47, 0, i, 47});
    }

    while (! que.empty()) {
        auto [t, s, i, d] = que.top();
        que.pop();
        auto aa = query(t, i) == first_st[i];
        if (s == 0) {
            auto prv_tm = t - d;
            if (aa) {
                que.push({t+d-1, 0, i, d-1});
            } else {
                que.push({prv_tm+half_t, 1, i, 0});
            }
        } else {
            assert(s == 1);
            if (aa) {
                if (first_st[i]) {
                    ans[i] = t - half_t;
                } else {
                    ans[i] = t;
                }
            } else {
                if (t == lst_tm) {
                    if (first_st[i]) {
                        ans[i] = 12*60;
                    } else {
                        ans[i] = 0;
                    }
                } else {
                    que.push({t+1, 1, i, d+1});
                }
            }
        }
    }

    answer(ans);
}

int main() {
    for (int i=0; i<lst_tm; ++i) {
        sel_tm = i;
        ct = 0;
        sol(1);
    }
    // sel_tm = 48;
    // ct = 0;
    // sol(1);
}