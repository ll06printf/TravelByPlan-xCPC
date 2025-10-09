#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pil = pair<int, ll>;
using pii = pair<int, int>;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Dor(i,a,b) for(int i=(a);i>=(b);--i)

#define eb emplace_back

template <class T>
auto &operator<<(ostream &os, const vector<T> &x) {
    int n = x.size();
    os << '[';
    For (i, 0, n - 1) {
        if (i > 0) os << ", ";
        os << x[i];
    }
    os << ']';
    return os;
}

template <class T>
void cmin(T &x, T y) {
    if (y > x) x = y;
}

void sol() {
    int n, m;
    cin >> n >> m;

    vector e(n + 1, vector<pil>());
    For (i, 1, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        e[u].eb(v, w);
        e[v].eb(u, w);
    }

    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}
