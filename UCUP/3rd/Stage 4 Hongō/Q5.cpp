#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

default_random_engine e(114514);
uniform_int_distribution<i64> d(1, 10);

vector<i64> rnd_iv(int n) {
    vector<i64> rt;
    for (int i=0; i<n ;++i) {
        rt.push_back(d(e));
    }
    return rt;
}

i64 count_cost(vector<i64> &a) {
    auto n = a.size();
    i64 ans = 0;
    for (int i=0; i<n; ++i) {
        auto ni = (i + 1) % n;
        ans += a[ni] / a[i];
    }
    return ans;
}


const int N = 1e6 + 10;
int a[N];
bool v[N];
i64 sov1(int n, vector<i64>& ra) {
    ranges::copy(ra, a);
    for(int i = 0;i < n;i ++){
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
        // if(a[i] > a[i - 1]){
        //     i -= 1;
        //     if(i < 0)
        //     break;
        // }
       if( bac / a[i] +  a[0] / s.top()  >= a[0] / a[i] +  a[i] / s.top()){

            if(v[i + 1] == 0){
                int x = s.top();
                s.pop();
                if(x / s.top() + v[i] / x + a[0] / v[i] > v[i] / s.top() + a[0] / a[i]){
                    v[i + 1] = 1;
                }else
                s.push(x);
            }
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
    for (int i=0; i<n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    // for(int i = 0;i < n - 1;i ++ )
    if(n >= 4){
            for(int i = 1;i < n - 1;i ++){
            if(ans[i - 1] == ans[i] && ans[i + 1] == ans[i + 2] && a[i ] / a[i + 1] < 2){
                swap(ans[i],ans[i + 1]);
            }
            }
    }
    ans[n] = ans[0];
    for(int i = 0;i < n - 1;i ++){
        if(ans[i + 1] / ans[i] + ans[i + 2]/ ans[i + 1] + ans[i + 3] / ans[i + 2] > ans[i + 2] / ans[i] + ans[i + 1]/ ans[i + 2] + ans[i + 3]/ ans[i +1])
        swap(ans[i + 1],ans[i + 2]);
    }
    for(int i = 0;i < n;i ++){
        sum += ans[i + 1] / ans[i];
        // cout << ans[i] << ' ';
    }
    
    // cout << a[n] ;
    // cout << endl;
    for (int i=0; i<n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> n;
    // vector<i64> a(n);
    // for (auto &&ai : a) {
    //     cin >> ai;
    // }

    while (true) {
        int n = 6;
        auto a = rnd_iv(n);
        auto a1 = a;
        auto ans1 = sov1(n, a1);

        ranges::sort(a);
        i64 ans2 = LLONG_MAX;
        vector<i64> mx;
        do {
            auto cans = count_cost(a);
            if (ans2 > count_cost(a)) {
                ans2 = cans;
                mx = a;
            }
        } while (ranges::next_permutation(a).found); 

        if (ans1 > ans2) {
            cout << "Error founded: ";
            for (auto ai : mx) {
                cout << ai << ' ';
            } 
            cout << endl;
            cout << "Ans " << ans2 << endl;
            cout << "Return " << ans1 << endl;
            return 0;
        }
    }
}