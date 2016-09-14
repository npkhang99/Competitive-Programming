#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=5009;

int n, k, a[N], b[N], c[N][N]={}, d[N], L[N], Lmax=0;

int main(){
    // freopen("ApRobot.inp","r",stdin);
    // freopen("ApRobot.out","w",stdout);
    scanf("%d%d\n",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&a[n-1-i]);
        b[n-1-i] = a[n-1-i];
    }
    sort(b,b+n);
    int num = n/k;
    for(int i=0; i<n; i++){
        c[i/k][b[i]] += 1;
        d[i] = -1;
    }
    for(int i=0; i<n; i++)
        if(c[i/k][a[i]]){ d[i] = i/k; c[i/k][a[i]] -= 1; }
    for(int i=0; i<n; i++)
        if(d[i]==-1)
            for(int j=0; j<=n/k; j++)
                if(c[j][a[i]]){ d[i] = j; c[j][a[i]] -= 1; break; }
    // for(int i=0; i<n; i++)
        // printf("%d %d\n",a[i],d[i]);
    L[0] = 1;
    for(int i=1; i<n; i++){
        L[i] = 1;
        for(int j=0; j<i; j++)
            if(d[i]>=d[j]) L[i] = max(L[i], L[j]+1);
        Lmax = max(L[i],Lmax);
    }
    int ans = (n-Lmax);
    printf("%d\n",ans);
    return 0;
}