#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> name;
    vector<int> p;
    for (int i=0; i<n; ++i) {
        string str;
        int a;
        cin >> str >> a;
        name.push_back(std::move(str));
        p.push_back(a);
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, greater<>{}, [&] (int i) {
        return p[i];
    });

    vector<int> rk(n);
    string ans;
    for (int i=0; i<n; ++i) {
        if (i == 0 || p[id[i-1]] != p[id[i]]) {
            rk[id[i]] = i + 1;
        } else {
            rk[id[i]] = rk[id[i-1]];
        }
    }
    for (int i=0; i<n; ++i) {
        auto rki = rk[i];
        auto &&cur_name = name[i];
        auto nlen = cur_name.size();
        if (rki < nlen) {
            ans += string_view(cur_name.begin(), cur_name.begin()+nlen - rki);
        }
    }
    ans[0] = toupper(ans[0]);

    cout << "Stage: " << ans << endl;

}