#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct ops {
    int op;
    variant<vector<i64>, i64> opp;
};

const i64 mx_sz = 1000'000'000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ops> op_seq;
    i64 seq_sz = 1;
    op_seq.push_back({1, vector<i64>{1}});

    for (int qi=0; qi<n; ++qi) {
        int op;
        i64 x;
        cin >> op >> x;

        if (op == 1) {
            auto &&bk_op = op_seq.back();
            if (bk_op.op == 2) {
                op_seq.push_back({1, vector<i64>{}});
            }
            get<0>(op_seq.back().opp).push_back(x);
            seq_sz = min(seq_sz + 1, mx_sz);
        } else if (op == 2) {
            op_seq.push_back({2, x});
            seq_sz = min(seq_sz * 2, mx_sz);
        } else {
            assert(op == 3);
            --x;
            if (x >= seq_sz) {
                cout << -1 << endl;
            } else {
                auto op_sz = op_seq.size();
                for (int i = op_sz - 1; i >= 0; --i) {
                    auto &&cur_op = op_seq[i];
                    if (cur_op.op == 1) {
                        auto &&opx = get<0>(cur_op.opp);
                        if (x < opx.size()) {
                            cout << opx[opx.size() - 1 - x] << endl;
                            break;
                        } else {
                            x -= opx.size();
                        }
                    } else {
                        assert(cur_op.op == 2);
                        auto xx = get<1>(cur_op.opp);
                        if (x % 2 == 0) {
                            cout << xx << endl;
                            break;
                        } else {
                            x /= 2;
                        }
                    }
                }
            }
        }
    }

    return 0;
}