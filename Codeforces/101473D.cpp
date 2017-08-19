#include <bits/stdc++.h>
using namespace std;

const int N = 19;

int n, m, a[N]={}, b[N]={}, dp[N][N][N][N]={};

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    for(int i = 1; i <= n; i++)
        dp[0][1][n][i] = a[i];

    for(int len = 0; len < n; len++){
        for(int l = len + 1; l <= len + 1; l++){
            int r = n;
            for(int p = l; p <= l + (r - l + 1) / 2; p++){
                int ln = p+1, rn = r;
                for(int i = 0; i < p - l + 1; i++)
                    dp[len + 1][ln][rn][ln + i] += dp[len][l][r][l + i];
                for(int i = ln; i <= rn; i++)
                    dp[len + 1][ln][rn][i] += dp[len][l][r][i];
                // for(int i = ln; i <= rn; i++)
                //     dp[1][n][ln][rn][i] = dp[len + 1][ln][rn][i];
            }
        }
    }

    for(int l = 1; l <= 15; l++){
        for(int ln = l+1; ln <= n; ln++){
            int rn = n, found = 1;
            if(rn - ln + 1 < m) continue;
            for(int i = 0; i < m; i++)
                if(dp[l][ln][rn][ln + i] != b[i + 1]){
                    found = 0;
                    break;
                }
            if(found){ printf("S\n"); return 0; }
            found = 1;
            for(int i = 0; i < m; i++)
                if(dp[l][ln][rn][ln + i] != b[m - i]){
                    found = 0;
                    break;
                }
            if(found){ printf("S\n"); return 0; }
        }
    }

    printf("N\n");
    return 0;
}
