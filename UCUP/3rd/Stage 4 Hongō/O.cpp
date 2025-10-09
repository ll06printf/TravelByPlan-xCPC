#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using pii = pair<int, int>;
#define eb emplace_back
#define fi first 
#define se second
using i64 = long long;

void sol();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

void sol() {
    int n, m;
    cin >> n >> m;

    vector esum(n + 1, vector<int>(n + 1)), osum(n + 1, vector<int>(n + 1));

    For (i, 1 , m) {
        int l, r;
        cin >> l >> r;
        if (l & 1) osum[l][r] += 1;
        else esum[l][r] += 1;
    }

    For (i, 1, n) For (j, 1, n) {
        esum[i][j] += esum[i][j - 1];
        osum[i][j] += osum[i][j - 1];
    }
    For (j, 1, n) Dor (i, n, 1) {
        esum[i][j] += (i < n ? esum[i + 1][j] : 0);
        osum[i][j] += (i < n ? osum[i + 1][j] : 0);
    }

    // For (i, 1, n) For (j, 1, n) {
    //     cout << i << ' ' << j << ' ' << esum[i][j] << endl;
    // }

    auto get = [&](vector<vector<int>> sum, int j, int i) {
        return sum[j][i];
    };

    vector<int> f(n + 1);
    For (i, 1, n) {
        For (j, 0, i - 1) {
            f[i] = max(f[i], f[j] + max(get(osum, j + 1, i), get(esum, j + 1, i)));
        }
    }

    // For (i, 1, n) {
    //     cout << f[i] << ' ';
    // }
    // cout << endl;

    cout << f[n] << endl;
}