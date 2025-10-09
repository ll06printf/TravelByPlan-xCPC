#include <bits/stdc++.h>

using namespace std;

#define int long long

using ll = long long;

mt19937_64 gen;
ll rnd(ll l, ll r) {
    uniform_int_distribution<ll> rnd(l, r);
    return rnd(gen);
}

int bf(int n, ll A, ll B, vector<int> a) {
    vector<int> id(2 * n);

    iota(id.begin(), id.end(), 0);

    int tans = -1;
    do {
        bool ok = 1;
        int ans = 0;
        for (int i = 0; i < 2 * n; i += 2) {
            ll d = abs(a[id[i]] - a[id[i + 1]]);
            if (d > A) {
                ok = 0;
                break;
            }
            if (d <= B) ++ans;
        }

        if (ok) {
            tans = max(ans, tans);
        }

    } while (next_permutation(id.begin(), id.end()));



    // iota(id.begin(), id.end(), 0);
    // do {
    //     bool ok = 1;
    //     int ans = 0;
    //     for (int i = 0; i < 2 * n; i += 2) {
    //         ll d = abs(a[id[i]] - a[id[i + 1]]);
    //         if (d > A) {
    //             ok = 0;
    //             break;
    //         }
    //         if (d <= B) ++ans;
    //     }

    //     if (ok) {
    //         if (ans == tans) {
    //             for (int i = 0 ;i < 2 * n; ++i) cout << a[id[i]] << ' ';
    //             cout << endl;
    //         }
    //     }

    // } while (next_permutation(id.begin(), id.end()));

    return tans;
}

int solve(int n, int a, int b, vector<int> aa){
    n *= 2;
    sort(aa.begin(),aa.end());
    // for(int i = 1;i < n;i ++){
    //     if(aa[i] - aa[i - 1] > a){
    //         // cout << -1 << endl;
    //         return -1;
    //     }
    // }
    deque<int> q;
    int ans = 0;
    for(int i = 0;i < n;i ++){
        if(q.empty()){
            q.push_back(aa[i]);
        }else{
            int tmp = q.back();
            if(aa[i] - tmp <= b){
                ans ++;
                q.pop_back();
                continue;
            }
            while(q.size() >= 2 && aa[i] - q.front() > a){
                q.pop_front();
                q.pop_front();
            }
            if(!q.empty () && aa[i] - q.front() > a){
                if(q.front() == aa[i - 1]){
                    return -1;
                }
                q.pop_front();

                if(aa[i] - aa[i - 1] > a){
                    // cout << -1 << endl;
                    return -1;
                }
                if(aa[i] - aa[i - 1] > b){
                    ans--;
                    q.push_back(aa[i - 1]);
                    q.push_back(aa[i]);
                }
            }else{
                q.push_back(aa[i]);
            }
        }
    }
    assert(q.size() % 2 == 0);
    // cout << ans << endl;
    return ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while( t--){
        int n = 4;
        const ll V = 10;
        vector<ll> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) a[i] = rnd(1, V);
        
        for (int A = 1; A <= V; ++A) for (int B = 1; B < A; ++B) {
            int tans = bf(n, A, B, a);
            int ans = solve(n, A, B, a);
            if (ans != tans) {
                cout << "Err " << ans << ' ' << tans << endl;
                cout << n << ' ' << A << ' ' << B << endl;
                sort(a.begin(), a.end());
                for (int i = 0; i < 2 * n; ++i) cout << a[i] << ' ';
                cout << endl;
            }
        }
    }
}