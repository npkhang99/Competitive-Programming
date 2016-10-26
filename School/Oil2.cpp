#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1509;

int n, m, x, a[N][N];
long long L[N][N]={};

int main(){
    // freopen("Oil2.inp","r",stdin);
    // freopen("Oil2.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++) L[i][1] = a[i][1];
    for(int i=1; i<=m; i++) L[1][i] = a[1][i];
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            L[i][j] = L[i-1][j] + L[i][j-1] - L[i-1][j-1] + a[i][j];
    long long t1=0, t2=0, ans=0;
    // for(int k=x; k<=m-x+1; k++){
        // t1 = t2 = 0;
        // for(int i=1; i<=n-x+1; i++)
            // for(int j=1; j<=k-x+1; j++)
                // t1 = max(t1, L[i+x-1][j+x-1] - L[i+x-1][j-1] - L[i-1][j+x-1] + L[i-1][j-1]);
        // for(int i=1; i<=n-x+1; i++)
            // for(int j=k+1; j<=m-x+1; j++)
                // t2 = max(t2, L[i+x-1][j+x-1] - L[i+x-1][j-1] - L[i-1][j+x-1] + L[i-1][j-1]);
        // ans = max(ans, t1+t2);
    // }
    
    // for(int k=x; k<=n-x+1; k++){
        // t1 = t2 = 0;
        // for(int i=1; i<=k-x+1; i++)
            // for(int j=1; j<=m-x+1; j++)
                // t1 = max(t1, L[i+x-1][j+x-1] - L[i+x-1][j-1] - L[i-1][j+x-1] + L[i-1][j-1]);
        // for(int i=k+1; i<=n-x+1; i++)
            // for(int j=1; j<=m-x+1; j++)
                // t2 = max(t2, L[i+x-1][j+x-1] - L[i+x-1][j-1] - L[i-1][j+x-1] + L[i-1][j-1]);
        // ans = max(ans, t1+t2);
    // }
    
    for(int i=1; i<=n-k+1; i++)
        for(int j=1; j<=m-k+1; i++)
            if(L[i+k-1][j+k-1] - L[i+k-1][j-1] - L[i-1][j+k-1] + L[i-1][j-1] > t1){
                t1 = L[i+k-1][j+k-1] - L[i+k-1][j-1] - L[i-1][j+k-1] + L[i-1][j-1];
                i1 = i; j1 = j;
            }
            
    for(int i=1; i<=n-k+1; i++)
        for(int j=1; j<=)
    
    printf("%lld\n",ans);
    return 0;
}