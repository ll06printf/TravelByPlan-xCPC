#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int get_num(const string &str) {
    return stoi(string{str.begin() + 3, str.end()});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, vector<int>> lst;
    
    string buf;
    while (getline(cin, buf)) {
        stringstream in(buf);
        string tsk;
        in >> tsk;
        assert(tsk.back() == ':');
        tsk.pop_back();
        auto tsk_id = get_num(tsk);

        bool nxt;
        do {
            string bg;
            in >> bg;
            if (bg.back() == ',') {
                nxt = true;
                bg.pop_back();
            } else {
                nxt = false;
            }
            auto bg_id = get_num(bg);

            lst[bg_id].push_back(tsk_id);
        } while (nxt);
    }

    for (auto &&[bg, tsk_lt] : lst) {
        cout << "CS-" << bg << ": ";
        auto len = tsk_lt.size();
        for (int i=0; i<len; ++i) {
            cout << "CS-" << tsk_lt[i];
            if (i != len-1) {
                cout << ", ";
            } else {
                cout << endl;
            }
        }
    }

}