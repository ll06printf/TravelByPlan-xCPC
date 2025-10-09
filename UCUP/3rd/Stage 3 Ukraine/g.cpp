#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int ans[N];

int a[N];
int pos[N];
int v[N];

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pos[a[i]] = i;
        if(a[i] == i){
            ans[cnt ++] = i;
            v[i] = 0;
        }else
            v[a[i]] = 1;
    }
    int per = 0;
    for(int i = 1;i <= n;i ++){
        if(per == 0 && v[i]){
            ans[cnt ++] = i;
            per = a[i];
           // cout << i << ' ' << a[i] << endl;
            v[i] = 0;
            while(per){
               // cout << 'p' << per << endl;
                if(v[per] == 0)
                    per = 0;
                else{
                    ans[cnt ++] = per;
                    v[per] = 0;
                    per = a[per];
                }
            }
        }
    }
    for(int i = 0;i < n;i ++)
        cout << ans[i] << " \n"[i == n- 1];
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while( t--){
        solve();
    }
}