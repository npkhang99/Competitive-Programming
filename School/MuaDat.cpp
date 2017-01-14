#include <stdio.h>
#include <math.h>

int n, dp[60009];

int min(int a, int b){ return (a<b)?a:b; }

void printAns(int n){
    if(n==0) return;
    for(int i=1; i<=sqrt(n); i++)
        if(dp[n-i*i] == dp[n]-1){
            printAns(n-i*i);
            printf("%d ",i);
            break;
        }
}

int main(){
    // freopen("MuaDat.inp","r",stdin);
    // freopen("MuaDat.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++) dp[i] = 10E8;
    for(int i=1; i<=sqrt(n); i++) dp[i*i] = 1;
    for(int i=2; i<=n; i++)
        for(int j=1; j<=sqrt(i); j++)
            dp[i] = min(dp[i],dp[j*j] + dp[i-j*j]);
    // printf("%d\n",dp[n]);
    printAns(n);
    printf("\n");
    return 0;
}
