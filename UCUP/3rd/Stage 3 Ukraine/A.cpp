#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string t;
        cin >> t;
        map<char, int> cnt;
        for (auto ch : t) {
            ++cnt[ch];
        }

        bool any_one = ranges::any_of(cnt, [](auto x) {return x.second == 1; });
        if (cnt.size() >= 3 || any_one) {
            cout << "YES" << endl;
            if (cnt.size() >= 3) {
                ranges::sort(t);
                cout << t.back();
                for (int i=0; i<t.size()-1; ++i) {
                    cout << t[i];
                }
                cout << endl;
            } else {
                auto sch = ranges::find_if(cnt, [](auto x) {return x.second == 1;})->first;
                cout << sch;
                for (auto ch : t) {
                    if (ch != sch) {
                        cout << ch;
                    }
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}