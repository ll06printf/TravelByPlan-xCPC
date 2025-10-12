#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define For(i,a,b) for(int i{a};i<=(b);++i)
#define Dor(i,a,b) for(int i{a};i>=(b);--i)

#define mtest int T; cin >> T; For(_tid, 0, T - 1)

#define eb emplace_back

vector<int> sieve(int n) {
    vector<int> pri;
    vector<bool> notp(n + 1);
    For (i, 2, n) {
        if (!notp[i]) pri.eb(i);
        for (auto p : pri) {
            if (p > n / i) break;
            notp[i * p] = 1;
            if (i % p == 0) break; 
        }
    }

    return pri;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto pri = sieve(1e5 + 100);

    mtest {
        ll n;
        cin >> n;

        vector<pii> ps;
        for (auto p : pri) {
            if (p > n) break;

            int c = 0;
            while (n % p == 0) {
                n /= p;
                ++c;
            }

            ps.eb(p, c);
        }
        if (n > 1) ps.eb(n, 1);
    
        ll ans = 1;
        for (auto [p, c] : ps) {
            ans *= 2 * c + 1;
        }

        cout << (ans + 1) / 2 << endl;
    }
}