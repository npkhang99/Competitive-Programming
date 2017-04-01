// PTIT
#include <bits/stdc++.h>
using namespace std;

#define BIT(i,mask) ((mask >> i) & 1)

const int N = 23;

int n, k, a[N][N]={}, dp[1 << N]={};

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    int m = (1 << n) - 1;
    memset(dp, 63, sizeof dp);
    dp[m] = 0;
    for(int drink = n; drink > k; drink--){
        for(int mask = 1; mask <= m; mask++)
            if(__builtin_popcount(mask) == drink){
                for(int i=0; i<n; i++)
                    if(BIT(i,mask)){
                        int next_mask = mask - (1 << i);
                        for(int j=0; j<n; j++)
                            if(BIT(j, next_mask)) dp[next_mask] = min(dp[next_mask], dp[mask] + a[i][j]);
                    }
            }
    }

    int ans = 0x3f3f3f3f;
    for(int mask=1; mask<=m; mask++)
        if(__builtin_popcount(mask) == k) ans = min(ans, dp[mask]);

    printf("%d\n", ans);
    return 0;
}
