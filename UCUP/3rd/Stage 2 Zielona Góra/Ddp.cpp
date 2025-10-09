#include <bits/stdc++.h>
#include <random>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define For(i,a,b) for(int i =(a);i<=(b);++i)
#define Dor(i,a,b) for(int i =(a);i>=(b);--i)

mt19937_64 gen;
ll rnd(ll l, ll r) {
    uniform_int_distribution<ll> rnd(l, r);
    return rnd(gen);
}

const int mod = 1e9 + 7;

int mul(int x, int y) {
    return ll(x) * y % mod;
}

int add(int x, int y) {
    int r = x + y;
    if (r >= mod) r -= mod;
    return r;
}

int qpow(int x, ll y) {
    int r = 1;
    for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
    return r;
}

int bf(int n, vector<ll> a) {

    vector<ll> S(n + 1);
    For (i, 1, n) {
        S[i] = S[i - 1] ^ a[i];    
    }

    vector<int> f(n + 1);
    f[0] = 1;
    For (i, 1, n) {
        For (j, 0, i - 1) {
            f[i] = add(f[i], mul(f[j], (S[i] ^ S[j]) % mod));
        }
    }

    return f[n];
}

int sol(int n, vector<ll> a);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    For (i, 1, T) {
        int n = 100;
        
        vector<ll> a(n + 1);
        For (i, 1, n) a[i] = rnd(1, 1e18);
        int tans = bf(n, a);
        int ans = sol(n, a);
        if (tans != ans) {
            cout << "Err " << tans << ' ' << ans << endl;
            cout << n << endl;
            For (i, 1, n) cout << a[i] << ' ';
            cout << endl;
        }
    }
}

int sol(int n, vector<ll> a) {
    // int n;
    // cin >> n;

    // vector<int> a(n + 1);

    int logv = 62;

    vector T(n + 1, vector<bool>(logv));
    For (i, 1, n) {
        cin >> a[i];
        For (j, 0, logv - 1) {
            T[i][j] = T[i - 1][j] ^ (a[i] >> j & 1);
        }
    }

    vector<int> f(n + 1);
    vector lst(logv, vector<int>(2));
    For (i, 0, logv - 1) lst[i][0] = 1;
    For (i, 1, n) {
        int ctb = 0;
        For (j, 0, logv - 1) {
            ctb = add(ctb, mul(qpow(2, j), lst[j][!T[i][j]]));
        }   
        f[i] = ctb;

        For (j, 0, logv - 1) {
            lst[j][T[i][j]] = add(lst[j][T[i][j]], f[i]);
        }
        // cout << i << ' ' << f[i] << endl;  
    }
    return f[n];
}