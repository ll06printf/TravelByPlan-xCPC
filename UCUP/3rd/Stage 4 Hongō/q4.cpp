#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;
int a[N];
bool v[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        v[i] = 1;
    }
    sort(a,a + n);
    reverse(a,a+n);
    // for(int i = 1;i <= n - 3;i ++){
    //     if(a[i - 1] == a[i] && a[i + 1] == a[i + 2] && a[i] / a[i + 1] < 2)
    //         swap(a[i],a[i + 1]);
    // }
    for(int i = 0;i < n;i ++)
        cout << a[i] << " \n"[i == n -1];
    vector<int> ans;
    stack<int> s;
    s.push(a[n - 1]);
//    cout << a[n - 1] << endl;
    int bac = a[n - 1];
    for(int i = n - 2;i > 0;i --){
        if(a[i] > a[i - 1]){
            i -= 2;
            if(i < 0)
            break;
        }
        if( bac / a[i] +  a[0] / s.top()  > a[0] / a[i] +  a[i] / s.top()){
            v[i] = 0;
            s.push(a[i]);
            // cout << 'i' <<  i << ' ' << endl;
        }else
            bac = a[i];
    }
    stack<int> ss;
    ss.push(a[0]);
    while(s.size() > 1){
        ss.push(s.top());
        s.pop();
    }
    for(int i = 0;i < n;i ++)
        if(v[i]){
            ans.push_back(a[i]);
        }
    while(!ss.empty()){
        ans.push_back(ss.top());
        // cout << 's' << ss.top();
        ss.pop();
    }
    int sum = 0;
    if(n >= 4){
            for(int i = 1;i < n - 1;i ++){
            if(ans[i - 1] == ans[i] && ans[i + 1] == ans[i + 2] && a[i ] / a[i + 1] < 2){
                swap(ans[i],ans[i + 1]);
            }
            }
    }
    ans[n] = ans[0];
    for(int i = 0;i < n;i ++){
        sum += ans[i + 1] / ans[i];
        cout << ans[i] << ' ';
    }
    cout << a[n] ;
    cout << endl;
    // cout << ans[n] ;
    // cout << endl;
    cout << sum << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --){
        solve();
    }
}