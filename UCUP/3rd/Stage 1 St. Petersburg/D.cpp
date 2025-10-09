#include <bits/stdc++.h>
using namespace std;

const auto lst_tm = 23 * 60 + 59;

bool query(int t, int i) {
    auto hh = t / 60;
    auto mm = t % 60;
    cout << format("at {:02}:{:02} check {}", hh, mm, i+1) << endl;
    string ans;
    cin >> ans;
    return ans == "awake";
}

void answer(const vector<int> &ans) {
    cout << "answer" << endl;
    for (auto tt : ans) {
        auto hh = tt / 60;
        auto mm = tt % 60;
        cout << format("{:02}:{:02}", hh, mm) << endl;
    }
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const auto half_t = 12 * 60;

    int n;
    cin >> n;

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