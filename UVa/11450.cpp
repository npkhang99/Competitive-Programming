#include <cstdio>
#include <cstring>
using namespace std;

int n, m, a[29][29];
bool dp[29][209];

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&m,&n);
        for(int i=0; i<n; i++){
            scanf("%d",&a[i][0]);
            for(int j=1; j<=a[i][0]; j++)
                scanf("%d",&a[i][j]);
        }

        memset(dp, false, sizeof dp);
        for(int i=1; i<=a[0][0]; i++)
            if(a[0][i] <= m)
                dp[0][m - a[0][i]] = true;

        for(int i=1; i<n; i++)
            for(int j=0; j<=m; j++)
                if(dp[i-1][j])
                    for(int k=1; k<=a[i][0]; k++)
                        if(j - a[i][k] >= 0)
                            dp[i][j - a[i][k]] = true;

        int ans;
        for(ans=0; ans<=m; ans++)
            if(dp[n-1][ans]) break;

        if(ans == m+1) printf("no solution\n");
        else printf("%d\n",m - ans);
    }
    return 0;
}
