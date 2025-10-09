#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

default_random_engine e(114514);
uniform_int_distribution<i64> d(1, 10);

vector<i64> rnd_iv(int n) {
    vector<i64> rt;
    for (int i=0; i<n ;++i) {
        rt.push_back(d(e));
    }
    return rt;
}

i64 count_cost(vector<i64> &a) {
    auto n = a.size();
    i64 ans = 0;
    for (int i=0; i<n; ++i) {
        auto ni = (i + 1) % n;
        ans += a[ni] / a[i];
    }
    return ans;
}

i64 sov1(int n, vector<i64>& a) {
    ranges::sort(a, greater<>{});

    list<i64> la(a.begin(), a.end());
    auto e_iter = prev(la.end());
    auto f_iter = la.begin();
    auto ae_val = *f_iter;
    auto pe_val = *e_iter;
    for (auto cur_iter = prev(e_iter); cur_iter != f_iter; ) {
        i64 old_val = ae_val / pe_val + *next(cur_iter) / *cur_iter + *cur_iter / *prev(cur_iter);
        i64 new_val = *cur_iter / pe_val + ae_val / *cur_iter + *next(cur_iter) / *prev(cur_iter);

        auto nxt = prev(cur_iter);
        if (new_val < old_val) {
            // ae_val = *cur_iter;
            pe_val = *cur_iter;
            auto cur_val = *cur_iter;
            la.erase(cur_iter);
            la.push_back(cur_val);
        }
        cur_iter = nxt;
    }

    a = {la.begin(), la.end()};

    for (int i=0; i+3 < n; ++i) {
        if (a[i] == a[i+1] && a[i+2] == a[i+3]) {
            swap(a[i+1], a[i+2]);
        }
    }

    cout << "Log ";
    for (auto ai : a) {
        cout << ai << ' ';
    }
    cout << endl;
    return count_cost(a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> n;
    // vector<i64> a(n);
    // for (auto &&ai : a) {
    //     cin >> ai;
    // }

    while (true) {
        int n = 6;
        auto a = rnd_iv(n);
        // auto a1 = a;
        // auto ans1 = sov1(n, a1);

        ranges::sort(a);
        i64 ans2 = LLONG_MAX;
        vector<i64> mx;
        do {
            auto cans = count_cost(a);
            if (ans2 > count_cost(a)) {
                ans2 = cans;
                mx = a;
            }
        } while (ranges::next_permutation(a).found); 

        for (auto ai : mx) {
            cout << ai << ' ';
        }
        cout << " Cost " << ans2 << endl;

        // if (ans1 > ans2) {
        //     cout << "Error founded: ";
        //     for (auto ai : mx) {
        //         cout << ai << ' ';
        //     } 
        //     cout << endl;
        //     cout << "Ans " << ans2 << endl;
        //     cout << "Return " << ans1 << endl;
        //     return 0;
        // }
    }
}