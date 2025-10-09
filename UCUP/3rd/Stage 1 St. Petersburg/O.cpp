#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define For(i,a,b) for (int i = (a); i <= (b); ++i)
#define Dor(i,a,b) for (int i = (a); i >= (b); --i)

using ll = long long;
using lf = long double;

int main() {
    lf A, B;
    int n, x1, xn;
    cin >> A >> B >> n >> x1 >> xn;

    vector<lf> x(n + 1);
    x[1] = x1;
    lf l = -1e9, r = 1e9;
    For (t, 1, 200) {
        lf m = (l + r) / 2;
        x[2] = m;
        For (i, 3, n) {
            x[i] = A * x[i - 1] + B * x[i - 2];
        }

        if (x[n] < xn) l = m;
        else r = m;
    }

    For (i, 1, n) {
        cout << fixed << setprecision(14) << x[i] << endl;
    }
}