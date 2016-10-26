#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1509;

int n, m, k, a[N][N];
long long L[N][N]={};

int main(){
    // freopen("Oil1.inp","r",stdin);
    // freopen("Oil1.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++) L[i][1] = a[i][1];
    for(int i=1; i<=m; i++) L[1][i] = a[1][i];
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            L[i][j] = L[i-1][j] + L[i][j-1] - L[i-1][j-1] + a[i][j];
    long long ans = 0;
    for(int i=1; i<=n-k+1; i++)
        for(int j=1; j<=m-k+1; j++)
            ans = max(ans, L[i+k-1][j+k-1] - L[i+k-1][j-1] - L[i-1][j+k-1] + L[i-1][j-1]);
    printf("%lld\n",ans);
    return 0;
}