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

template <class T>
void cmin(T &x, T y) {
    if (y > x) x = y;
}

ll sol(vector<int> vn, ll m) {

    vn = add(vn, 1);
    int ln = vn.size() - 1;

    int lm = 0;
    {
        int tm = m;
        while (tm) {
            ++lm;
            tm /= 10;
        }
    }

    auto calc = [&](vector<int> vn) {

        ll d1; 
        {
            int t = 0;
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
            int ln = vn.size() - 1;
    
            ll d2 = LLONG_MAX / 3;
    
            For (i, 1, ln - lm + 1) {
                ll t = seg(i, i + lm - 1);
                if (t == m) {
                    d2 = 0;
                }
            }
            
            For (i, ln - 2 * lm + 2, ln - lm + 1) {
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
        
            // cout << vn << endl;
            auto d3 = find(vn) + t1 - tt;
    
            // cout << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << find(vn) << endl;
    
            ll d = min({d1, d2, d3});
    
            return d;
        }
    };

    return calc(vn);

}

mt19937_64 gen;
int rnd(int l, int r) {
    uniform_int_distribution<int> rnd(l, r);
    return rnd(gen);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // For (j, 1, 10) 
    {
        int j = rnd(1, 1e6);
        For (ttt, 1, 100) {
            int l = rnd(1, 1e6);
            vector<int> a(1 + l);
            a[1] = rnd(1, 9);

            For (i, 2, l) a[i] = rnd(0, 9);

            auto ans = 1 + sol(a, j);

            auto bf = [&](vector<int> a, ll m) {
                
                auto chk = [&](vector<int> a, ll m) {
                    ll lm = 0;
                    int tm = m;
                    while (tm) {
                        lm += 1;
                        tm /= 10;
                    }
    
                    int ln = a.size() - 1;
                    For (i, 1, ln - lm + 1) {
                        ll t = 0;
                        For (j, i, i + lm - 1) {
                            t *= 10;
                            t += a[j];
                        }
                        if (t == m) return 1;
                    }
                    return 0;
                };

                a = add(a, 1);
                
                ll d1; 
                {
                    int t = 0;
                    for (auto tt : a) {
                        t *= 10;
                        t %= m;
                        t += tt;
                        t %= m;
                    }
                    d1 = (m - t) % m;
                }
            
                int ans = d1;
                For (i, 0, d1 - 1) {
                    if (chk(a, m)) {
                        ans = i;
                        break;
                    }

                    a = add(a, 1);
                }

                return ans + 1;
            };

            ll tans = bf(a, j);

            if (tans != ans) {
                cout << "Err " << tans << ' ' << ans << endl;
                cout << a << ' ' << j << endl;
            }
        }
    }
}
