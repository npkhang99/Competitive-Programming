// ACM ICPC 2017 World Finals
// Problem I - Secret Chamber at Mount Rushmore
#include <bits/stdc++.h>
using namespace std;

const int N = 59;

int n, m;
string start, final;
bool end_reached, b[59][256]={};
vector<char> a[256];

void dfs(int i, string s){
    if(i == s.size()){
        end_reached = true;
        return;
    }

    if(s[i] == final[i]) dfs(i+1, s);
    b[i][s[i]] = true;
    for(char c : a[s[i]]){
        if(b[i][c]) continue;
        s[i] = c;
        b[i][c] = true;
        dfs(i, s);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++){
        char x, y; cin >> x >> y;
        a[x].push_back(y);
    }

    while(n--){
        cin >> start >> final;

        if(start.size() != final.size()){
            cout << "no\n";
            continue;
        }

        end_reached = false;
        memset(b, 0, sizeof b);
        dfs(0,start);
        if(end_reached) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
