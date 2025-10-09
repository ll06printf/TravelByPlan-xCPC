#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n,a,b;
    vector<int> aa;
    cin >> n >> a >> b;
    n *= 2;
    for(int i = 0;i <  n;i ++){
        int x;
        cin >> x;
        aa.push_back(x);
    }
    sort(aa.begin(),aa.end());
    // for(int i = 1;i < n;i ++){
    //     if(aa[i] - aa[i - 1] > a){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
    deque<int> q;
    int ans = 0;
    for(int i = 0;i < n;i ++){
        // cout << i << ' ' << ans << endl;
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
                    cout << -1 << endl;
                    return;
                }
                q.pop_front();
                if(aa[i] - aa[i - 1] > a){
                    cout << -1 << endl;
                    return;
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
    cout << ans << endl;
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