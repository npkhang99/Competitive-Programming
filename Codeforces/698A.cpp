#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=109;

int n, a[N], dp[N][9]={};

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    for(int i=1; i<=n; i++){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if(a[i]==1 || a[i]==3) dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1);
        if(a[i]==2 || a[i]==3) dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1);
    }
    // for(int j=0; j<3; j++){
    //     for(int i=1; i<=n; i++) printf("%d ",dp[i][j]);
    //     printf("\n");
    // }
    int ans=0;
    for(int i=0; i<3; i++) ans = max(ans,dp[n][i]);
    printf("%d\n",n-ans);
    return 0;
}
