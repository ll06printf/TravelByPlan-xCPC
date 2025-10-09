#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n;

stack<int> s0;
stack<int> s1;
vector<int> ans1;
vector<int> ans0;

void solve(){
    cin >> n;
    for(int i = 2;i <= n;i ++){
        cout << '?' << ' ' << 1 << ' ' << i << endl;
        char c;
        cin >> c;
        if(c == 'R'){
            s0.push(i);
            ans0.push_back(1);
            ans0.push_back(i);
        }else{
            s1.push(i);
            ans1.push_back(1);
            ans1.push_back(i);
        }
    } 
    
    while(1){
        if(ans0.size() == 2 * (n - 1)){
            cout << '!' << endl;
            for(int i = 0;i < ans0.size();i += 2)
                cout << ans0[i] << ' ' << ans0[i + 1] << endl;
            return;
        }
        if(ans1.size() == 2 * (n - 1)){
            cout << '!' << endl;
            for(int i = 0;i < ans1.size();i += 2)
                cout << ans1[i] << ' ' << ans1[i + 1] << endl;
            return;
        }

        int x = s1.top();
        int y = s0.top();
        char c;
        cout << '?' << ' ' << x << ' ' << y << endl;
        cin >> c;
        if(c == 'R'){
            ans0.push_back(y);
            ans0.push_back(x);
            s1.pop();
        }else{
            ans1.push_back(y);
            ans1.push_back(x);
            s0.pop();
        }
    }
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}