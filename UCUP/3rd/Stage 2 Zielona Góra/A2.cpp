#include <bits/stdc++.h>
#include <random>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define For(i,a,b) for(int i =(a);i<=(b);++i)
#define Dor(i,a,b) for(int i =(a);i>=(b);--i)

mt19937_64 gen;
ll rnd(ll l, ll r) {
    uniform_int_distribution<ll> rnd(l, r);
    return rnd(gen);
}

const int N = 1e6 + 10;


// int n,m;
// int dp[N];
// bool v[N];
// int d1[N];
// int d[N];
// vector<int> e[N];

// vector<int> e1[N];

ll solve(int n, int m, vector<pii> edges){
    vector<int> dp(n + 1);
    vector<bool> v(n + 1);
    vector<int> d1(n + 1), d(n + 1);
    vector e(n + 1, vector<int>());
    vector e1(n + 1, vector<int>());
    // int n, m;
    // cin >> n >> m;
    for(int i = 0 ;i < m;i ++){
        // int u,v;
        // cin >> u >> v;
        auto [u, v] = edges[i];
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
    // cout << dp[n] << endl;

    return dp[n];
}

#define eb emplace_back

ll bf(int n, int m, vector<pii> edges) {
    vector e(n + 1, vector<pii>());
    int cnt = 0;
    for (auto [u, v] : edges) {
        ++cnt;
        e[u].eb(v, cnt);
    }

    vector<int> arr(n + 1);
    
    {
        vector e(n + 1, vector<int>());
        for (auto [u, v] : edges) {
            ++cnt;
            e[v].eb(u);
        }
        auto work = [&](auto &&work, int u) -> void {
            if (arr[u]) return;
            arr[u] = 1;
            for (auto v : e[u]) {
                work(work, v);
            }  
        };

        work(work, n);
    }



    vector<int> vis(m + 1); 
    vector<int> visn(n + 1);
    visn[n] = 1;
    int ans = 0;
    auto dfs = [&](auto && dfs, int u, bool emp) -> void {
        if (!arr[u]) return;
        if (visn[u] && emp) {
            // cout << "ctb at " << u << endl;
            ++ans;
            return ;
        }
        visn[u] = 1;
        
        for (auto [v, id] : e[u]) {
            if (!vis[id]) {
                auto [u, v] = edges[id - 1];
                // cout << "expand " << u << ' ' << v << endl;
                dfs(dfs, v, 1);
                vis[id] = 1;
            } else dfs(dfs, v, 0);
        }
    };

    dfs(dfs, 1, 0);

    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<pii> edges;
    For (i, 1, m) {
        int u, v;
        cin >> u >> v;
        edges.eb(u, v);
    }

    cout << bf(n, m, edges) << endl;
}