#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 19;

int n, m, dp[N][1 << N], a[N][N];
string st[19];

int f(string a, string b){
    int w = 0;
    for(int i=0; i<a.size(); i++)
        if(a[i] != b[i]) w+=1;
    return w;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Garlan.inp","r",stdin);
    // freopen("Garlan.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<m; i++) cin>> st[i];

    string FS(n,'0');
    for(int i=0; i<m; i++)
        for(int j=i+1; j<m; j++) a[i][j] = a[j][i] = f(st[i],st[j]);

    int _n = (1 << m) - 1;
    for(int mask = 1; mask <= _n; mask++)
        for(int i=0; i<m; i++) dp[i][mask] = 10E8;

    for(int i=0; i<m; i++) dp[i][1 << i] = f(FS,st[i]);

    for(int mask = 3; mask <= _n; mask++){
        int cnt = __builtin_popcount(mask);
        if(cnt < 2) continue;
        for(int i=0; i<m; i++)
            if((mask >> i) & 1){
                int preMask = mask - (1 << i);
                for(int j=0; j<m; j++)
                    if((preMask >> j) & 1)
                        dp[i][mask] = min(dp[i][mask], dp[j][preMask] + a[j][i]);
            }
    }

    int ans = 10E8;
    for(int i=0; i<m; i++) ans = min(ans,dp[i][_n]);
    cout<< ans<< '\n';
    return 0;
}
