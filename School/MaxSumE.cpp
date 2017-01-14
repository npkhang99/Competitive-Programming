#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1109;

int n, m, a[N][N]={};
long long dp[N][N]={};

int main(){
    freopen("MaxSumE.inp","r",stdin);
    freopen("MaxSumE.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + (a[i][j]%2==0? a[i][j]:0);

    printf("%lld\n",dp[n][m]);
    return 0;
}
