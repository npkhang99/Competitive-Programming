#include <bits/stdc++.h>
using namespace std;

const int N = 509;

int n, m, c[N][N]={}, t[N][N]={}, dp[N][N]={}, T, W;
vector<int> a[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("City.inp","r",stdin);
    // freopen("City.out","w",stdout);
    cin>> n>> m>> T>> W;
    for(int i=0; i<m; i++){
        int x, y; cin>> x>> y;
        cin>> t[x][y]>> c[x][y];
        t[y][x] = t[x][y]; c[y][x] = c[x][y];
        a[x].push_back(y); a[y].push_back(x);
    }

    for(int i=0; i<=T; i++)
        for(int j=1; j<=n; j++)
            dp[i][j] = 1e9;

    dp[0][1] = 0;
    for(int i=1; i<=T; i++){
        for(int u=1; u<=n; u++){
            dp[i][u] = min(dp[i][u], dp[i-1][u] + W);
            for(int j = 0; j<a[u].size(); j++){
                int v = a[u][j];
                if(i >= t[v][u]) dp[i][u] = min(dp[i][u], dp[i - t[v][u]][v] + c[v][u]);
            }
        }
    }

    cout<< (dp[T][n] == 1e9? -1:dp[T][n])<< '\n';
    return 0;
}
