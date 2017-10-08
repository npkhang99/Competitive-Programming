#include <bits/stdc++.h>
using namespace std;

const int N = 100009;
const long long MOD = 1e9 + 7;

int n;
string s, t;
long long hash1[N]={}, hash2[N]={}, POW[N]={};

long long get_hash_s(int i, int j){
    return (hash1[j] - hash1[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}

long long get_hash_t(int i, int j){
    return (hash2[j] - hash2[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    s = " " + s;
    t = " " + t;
    n = s.size();

    POW[0] = 1;
    for(int i = 1; i <= n; i++)
        POW[i] = (POW[i-1] * 17ll) % MOD;
    for(int i = 1; i <= n; i++)
        hash1[i] = (hash1[i-1] * 17ll + s[i] - 'a') % MOD;
    for(int i = 1; i <= n; i++)
        hash2[i] = (hash2[i-1] * 17ll + t[i] - 'a') % MOD;
    
    int q; cin >> q;
    while(q--){
        int x, y, i, j; cin >> x >> y;
        i = n - y;
        j = n - x;
        if(get_hash_s(x, x + (y - x + 1) / 2 - 1) == get_hash_t(i, i + (j - i + 1) / 2 - 1)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
