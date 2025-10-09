#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define For(i,a,b) for(int i =(a);i<=(b);++i)
#define Dor(i,a,b) for(int i =(a);i>=(b);--i)

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
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

void sol() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);

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

    cout << f[n] << endl;
}