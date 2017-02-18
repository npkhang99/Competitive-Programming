#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, m;
long long dp[2][N]={};
char a[N], b[N];

int main(){
    scanf("%s%s", a+1, b+1);
    n = strlen(a+1); m = strlen(b+1);
    for(int i=1; i<=m; i++){
        dp[b[i] - '0'][i] = dp[b[i] - '0'][i-1] + 1;
        dp[1 - b[i] + '0'][i] = dp[1 - b[i] + '0'][i-1];
    }

    long long ans = 0;
    for(int i=1; i<=n; i++)
        for(int c = 0; c < 2; c++){
            // fprintf(stderr, "%d %d - %d %d - %d\n", i, c, dp[c][m - n + i], dp[c][i -1], dp[c][m - n + i] - dp[c][i-1]);
            ans += ((a[i] - '0') != c) * (dp[c][m - n + i] - dp[c][i-1]);
        }

    printf("%lld\n", ans);
    return 0;
}
