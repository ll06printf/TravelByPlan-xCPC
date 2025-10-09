#include <bits/stdc++.h>
#include <vector>

using namespace std;

# define int long long

int n;


const int mod = 998244353;

const int inf = 1e9 + 10;

int qpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int pos[200010];

void solve(){
    cin >> n;
    vector<int> s;
    s.push_back(inf);
    int ans = 1;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        pos[x] = i;
        while(x > s.back()){
            s.pop_back();
        }
        int z = 1;
        if(s.back() != inf){
             z = i - pos[s.back()];        // cout << 'g' << z << ' ' << pos[s.back()] << endl;
        }
        // cout << 'z' << i << ' ' << z << ' ' << s.back()<< endl;
        ans = ans * max(1ll,(qpow(2,z) - 1 +  mod)) % mod;
        // cout << ans << endl;
        if(s.back() != inf)
             ans = ans * (qpow(2,pos[s.back()] - 1)) % mod;
        else
            ans = ans * (qpow(2,i - 1)) % mod;
        s.push_back(x); 
        // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}