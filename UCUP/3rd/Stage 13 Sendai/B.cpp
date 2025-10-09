#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using pii = pair<int, int>;
#define eb emplace_back
#define fi first 
#define se second

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

const int mod = 998244353;

int mul(int x, int y) {
    return ll(x) * y % mod;
}
int qpow(int x, ll y) {
    int r = 1;
    for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
    return r;
}

void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    For (i, 1, n) cin >> a[i];

    ll cnt = 0;
    Dor (i, n - 1, 1) {
        if (a[i] < a[i + 1]) {
            cnt += n - i;
        } else {
            cnt += n - i - 1;
        }
    }

    cout << qpow(2, cnt) << endl;
}