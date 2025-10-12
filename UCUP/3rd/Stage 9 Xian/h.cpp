#include <bits/stdc++.h>

using namespace std;

int n , m, k;
const int N = 1e7 + 10;
int pos[N],c[N];
int ans[N];


int lowbit(int x){
    return x & -x;
}


void fix(int x,int k){
    while(x <= n){
        c[x] += k;
        x = x + lowbit(x);
        // cout << 'f' << x << ' ' << k << endl;
    }
}


int get(int x){
    // cout << 'g' << x << endl;
    int res = 0;
    while(x > 0){
        res += c[x];
        x = x - lowbit(x);
        // cout << 'g' << x << endl;
    }
    return res;
}

int getsum(int p,int q,int len){
    return get((q + 1) * (1 << len))  - get(p * (1 << len));
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> k;
    n = 1 << m;
    for(int i = 0;i < n;i ++){
        int x;
        cin >> x;
        pos[x] = i;
        fix(i + 1, 1);
    }
    for(int i = 1;i <= n;i ++){
        fix(pos[i] + 1,-1);
        ans[pos[i]] = __lg(i);
        // cout << i << ' ' << pos[i] << ' ' << ans[pos[i]] << endl;
        for(int j = 0;j <= ans[pos[i]];j ++){
            int p = pos[i] / (1 << j);
            int q = p ^ 1;
            if(p > q)
                swap(q,p);
            // cout << i << ' ' << j << ' ' << p << ' ' << q << ' ' << getsum(p,q,j) << endl;
            if(getsum(p,q,j) > k){
                ans[pos[i]] = j;
                break;
            }
        }
        
    }
    for(int i = 0;i < n;i ++){
        cout << ans[i] << " \n"[i == n -1];
    }
}
