#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = (a);i<=(b);++i)
#define Dor(i,a,b) for(int i=(a);i>=(b);--i)

using ll = long long;


void sol(int n, ll l, ll r, vector<ll> a);
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    // while (T--) sol();

    int n;
    ll l, r;
    cin >> n >> l >> r;
    vector<ll> a(n + 1);
    For (i, 1, n) cin >> a[i];
    
    For (L, 1, 100) For (R, L, 100) {
        sol(n, L, R, a);
    }
}

template<class T>
ostream &operator<<(ostream &os, const vector<T>& v) {
    os << '[';
    int n = v.size();
    For (i, 0, n - 1) {
        if (i > 0) os << ", ";
        os << v[i];
    }
    os << ']';
    return os;
}

void sol(int n, ll l, ll r, vector<ll> a) {
    // int n;
    // cin >> n;
    // ll l, r;
    // cin >> l >> r;

    // vector<ll> a(n + 1);
    // For (i, 1, n) cin >> a[i];
    auto c = a;
    For (i, 2, n) a[i] /= a[i - 1];

    // cout << "a: " << a << endl;

    
    auto cvt = [&](ll x) {
        vector<ll> f(n + 1);
        For (i, 1, n) {
            f[i - 1] = x % a[i];
            x /= a[i];
        }
        f[n] = x;
        return f;
    };

    ll tans = 0;
    For (i, l, r) {
        auto t = cvt(i);
        reverse(t.begin(), t.end());
        bool ok = 0;
        for (auto x : t) {
            ok |= x & 1;
        }
        tans += ok;
        // cout << i << ' ' << t << endl;
    }

    auto calc = [&](ll x) {
        auto f = cvt(x);
        // cout << "f: " << f << endl;

        vector<ll> pfx(n + 1);
        pfx[1] = 1;
        For (i, 2, n) {
            pfx[i] = pfx[i - 1] * ((a[i] + 1) / 2);
        }

        ll ans = 0;
        bool isz = 1;
        Dor (i, n, 1) {
            ll ctb = (f[i] + 1) / 2;
            ans += ctb * pfx[i];
            if (f[i] & 1) {
                isz = 0;
                break;
            } 
        }

        ans += isz;

        return ans;
    };

    // ll t = calc(l - 1);
    // cout << l - 1 << ": " << t << endl;


    // ll t1 = calc(r);
    // cout << r << ": " << t1 << endl;

    ll ans = calc(r) - calc(l - 1);
    // cout << (r - l + 1) - ans << endl;
    ans = (r - l + 1) - ans;

    if (tans != ans) {
        cout << "Err " <<  tans << ' ' << ans << ' ' << l << ' ' << r << endl;
    }
}