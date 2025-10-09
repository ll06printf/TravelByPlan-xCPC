#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i = (a);i<=(b);++i)
#define Dor(i,a,b) for(int i=(a);i>=(b);--i)

using ll = long long;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(26);
    ll ans = 0;
    For (i, 0, n - 1) {
        char c = s[i];
        ans += i + 1 - cnt[c - 'a'];
        cnt[c - 'a'] += 1;
    }

    cout << ans << endl;
}