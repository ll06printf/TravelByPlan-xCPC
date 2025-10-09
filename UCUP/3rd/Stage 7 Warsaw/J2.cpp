#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int row_min = *min_element(a[i].begin(), a[i].end());
        ans = max(ans, row_min);
    }

    cout << ans << '\n';
    return 0;
}