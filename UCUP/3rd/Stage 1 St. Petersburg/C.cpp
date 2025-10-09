#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using lf = long double;
using pii = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;

    int V = 0;
    vector<int> a(n + 1);
    For (i, 1, n) {
        cin >> a[i];
        V = max(V, a[i]);
    }

    string s;
    cin >> s;
    s = ' ' + s;

    auto chk = [&](int x) {
        int t = 0;

        int ma = 0;
        For (i, 1, n) {
            if (a[i] >= x) {
                if (s[i] == '1') ++t, ma = max(ma, t);
                else t = 0;
            }
        }
        
        return ma >= k;
    };

    int l = 0, r = V;
    int ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (chk(m)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }

    cout << ans << endl;
}