#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}

#define eb emplace_back

void sol() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);

    For (i, 1, n) cin >> p[i];

    int cnt = 0;

    int t = 1;
    vector<bool> col(n + 1);
    do {
        ++cnt;
        col[t] = 1;
        t = p[t];
    } while (t != 1);

    if (cnt < n) {
        cout << n << endl;
        cout << cnt << endl;
        For (i, 1, n) {
            if (col[i]) cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << n - 2 << endl;
        vector<int> ans;
        int t = 1;
        while (t != 2) {
            ans.eb(t);
            t = p[t];
        }

        cout << ans.size() << endl;
        for (auto t : ans) cout << t << ' ';
        cout << endl;
    }
}