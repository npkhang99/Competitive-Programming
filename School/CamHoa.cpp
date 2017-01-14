#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int N=1009;

int n, m, a[N][N]={}, dp[N][N]={};

int main(){
    // freopen("CamHoa.inp","r",stdin);
    // freopen("CamHoa.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    // scanf("%d%d",&n,&m);
    cin>> n>> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            // scanf("%d",&a[i][j]);
            cin>> a[i][j];
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<=m; j++) dp[i][j] = -999999999;

    for(int i=1; i<=n; i++)
        for(int j=i; j<=m-n+i; j++)
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);

    printf("%d\n",dp[n][m]);
    return 0;
}
