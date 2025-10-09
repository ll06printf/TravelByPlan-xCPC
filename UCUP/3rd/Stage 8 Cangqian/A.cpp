#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

vector<int> add(vector<int> x, ll y) {
    // cout << "Add " << x << ' ' << y << endl;
    reverse(x.begin() + 1, x.end());
    int n = x.size() - 1;
    For (i, 1, n) {
        int &t = x[i];
        y += t;
        t = y % 10;
        y /= 10;
    }
    while (y) x.eb(y % 10), y /= 10;
    reverse(x.begin() + 1, x.end());
    return x;
}

void sol() {
    ll m;
    vector<int> vn(1);
    {
        string sn;
        cin >> sn >> m;
    
        for (auto t : sn) {
            vn.eb(t - '0');
        }
    }

    vn = add(vn, 1);

    int lm = 0;
    {
        int tm = m;
        while (tm) {
            ++lm;
            tm /= 10;
        }
    }

    auto calc = [&](vector<int> vn) {
        int ln = vn.size() - 1;
        ll d1; 
        {
            ll t = 0;
            for (auto tt : vn) {
                t *= 10;
                t %= m;
                t += tt;
                t %= m;
            }
            d1 = (m - t) % m;
        }
    
        // cout << ' ' << ln << ' ' << lm << ' ' << d1 << endl;
    
        auto seg = [&](int l, int r, ll t = 0) {
            For (i, l, r) {
                t *= 10;
                t += vn[i];
            }
            return t;
        };
    
        if (ln <= lm) {
            ll t = seg(1, ln);
            if (t <= m) {
                return m - t;
            } else {
                ll d2 = m * 10 - t;
                return min(d1, d2);
            }
        }
    
        auto find = [&](vector<int> &vn) {
            ll d2 = LLONG_MAX / 3;
    
            For (i, 1, ln - lm + 1) {
                ll t = seg(i, i + lm - 1);
                if (t == m) {
                    d2 = 0;
                    break;
                }
            }
            
            For (i, ln - 2 * lm, ln - lm + 1) {
                ll t1 = seg(i, ln);
                ll t = m;
                For (j, i + lm, ln) {
                    t *= 10;
                }
                // cout << i << ' ' << t << ' ' << t1 << endl;
                if (t >= t1) {
                    d2 = min(d2, t - t1);
                }
            }
    
            return d2;
        };
        
        {
            auto d2 = find(vn);
            ll tt = seg(ln - lm + 1, ln);
            ll t1 = 1;
            For (i, 1, lm) t1 *= 10;
        
            vn = add(vn, t1 - tt);
            ln = vn.size() - 1;
        
            // cout << vn << endl;
            auto d3 = find(vn) + t1 - tt;
    
            // cout << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << find(vn) << endl;
    
            ll d = min({d1, d2, d3});
    
            return d;
        }
    };

    ll d = calc(vn);

    vn = add(vn, d);
    For (i, 1, vn.size() - 1) cout << vn[i];
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}
