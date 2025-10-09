#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = (a);i<=(b);++i)
#define Dor(i,a,b) for(int i=(a);i>=(b);--i)

using ll = long long;

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}

ll calc(ll a, ll b, ll c) {
    ll s = (a + b + c) / 2;
    return s * (s - a) * (s - b) * (s - c);
}

void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    For (i, 1, n) cin >> a[i];

    sort(a.begin() + 1, a.end());
    ll ans = -1;
    For (i, 3, n) {
        if (a[i - 2] + a[i - 1] > a[i]) {
            ans = max(ans, calc(a[i - 2], a[i - 1], a[i]));
        }
    }

    cout << ans << endl;
}