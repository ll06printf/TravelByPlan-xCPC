#include <algorithm>
#include <bits/stdc++.h>
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
    cin >> T;
    while (T--) sol();
}

void sol() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (auto &&ai : a) {
        cin >> ai;
    }

    if (n & 1) {
        cout << "First" << endl;
    } else {
        auto mae = *min_element(a.begin(), a.end());
        auto m_ct = count(a.begin(), a.end(), mae);
        auto rem_ct = n - m_ct;

        bool ok = rem_ct % 2 == 1;
        cout << (ok ? "First" : "Second") << endl;
    }

}