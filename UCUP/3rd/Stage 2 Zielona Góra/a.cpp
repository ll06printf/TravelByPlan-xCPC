#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;


int n,m;
int dp[N];
bool v[N];
int d1[N];
int d[N];
vector<int> e[N];

vector<int> e1[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ;i < m;i ++){
        int u,v;
        cin >> u >> v;
        e1[v].push_back(u);
        e[u].push_back(v);
        d[v] ++;
        }
    queue<int> q;
    q.push(n);
    v[n] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
       // cout << 'v' << ' ' << tmp << endl;
        for(auto i : e1[tmp]){
            if(v[i] == 0){
                v[i] = 1;
                q.push(i);
            }
        }
    }

    dp[1] = 1;
    q.push(1);
    while(!q.empty()){
        int tmp = q.front();
       // cout << tmp << ' ' << dp[tmp] << endl;
        q.pop();
        int add = dp[tmp];
        for(auto i : e[tmp]){
            d[i] --;
            if(v[i]){
                dp[i] += add;
                add = 1;
            }
            if(d[i] == 0&& v[i])
                q.push(i);
        }
    }
    cout << dp[n] << endl;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}