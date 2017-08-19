#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> si;

struct comp {
    bool operator() (const si& a, const si& b) {
        if(a.first.size() != b.first.size()) {
            return a.first.size() > b.first.size();
        }

        if(a.first != b.first) {
            return a.first < b.first;
        }

        return a.second < b.second;
    }
};

int n, m;
string a[1000009];

bool compare(const string& a, const string& b) {
    if(a.size() != b.size()) {
        return a.size() > b.size();
    }
    return a < b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n){
        m = 0; memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++){
            string st; cin >> st;
            int k, x; cin >> k;
            for(int j = 0; j < k; j++){
                cin >> x;
                if(st.size() > a[x-1].size()) a[x-1] = st;
                m = max(m, (int)st.size() + x - 1);
            }
        }

        int last = -1;
        string ans(m,'a');
        for(int i = 0; i < 1000009; i++){
            if(a[i].empty()) continue;
            if(i + (int)a[i].size() - 1 <= last) continue;
            ans.replace(i, a[i].size(), a[i]);
            last = i + a[i].size() - 1;
        }

        cout << ans << endl;
    }
    return 0;
}
