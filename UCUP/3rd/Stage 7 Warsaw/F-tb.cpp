#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n=100;
    set<int> fbn{0, 1};
    {
        int p1 = 0;
        int p2 = 1;
        auto p3 = p1 + p2;
        while (p3 <= 2 * n) {
            fbn.insert(p3);
            p1 = p2;
            p2 = p3;
            p3 = p1 + p2;
        }
    }

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<n; ++j) {
            if (fbn.contains(i + j)) {
                cout << "O";
            } else {
                cout << ".";
            }
            // cout << ' ';
        }
        cout << endl;
    }
}