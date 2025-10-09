    #include <bits/stdc++.h>

    using namespace std;

    void solve(){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        bool c = 0;
        for(int i = 0;i < n;i ++ ){
            if(i == 0 && i == n - 1 && s[i] == '0')
                c = 1;
            if( i && s[i] == '0' && s[i - 1] == '0')
                c = 1;
            if(s[i] == '1')
                sum ++;
        }
        if(c)
            cout << sum << endl;
        else{
            int ans = sum * 2;
            int ss = 0;
            for(int i = 0; i < n;i ++){
                if(s[i] == '1')
                    ss ++;
                else{
                    ans = min(ans,sum + ss);
                    ss = 0;
                }
            }
            ans = min(ans,sum + ss);
            cout << ans << endl;
        }

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