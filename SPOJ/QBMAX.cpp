#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, m, a[N][N], dp[N][N];

int main(){
    cin>> n>> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>> a[i][j];
    memset(dp, 255 - 0x3f, sizeof dp);
    for(int i=1; i<=n; i++)
        dp[i][1] = a[i][1];
    for(int j=2; j<=m; j++)
        for(int i=1; i<=n; i++)
            dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1])) + a[i][j];

    int ans = -1e9;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[i][m]);
    cout<< ans<< endl;
    return 0;
}
