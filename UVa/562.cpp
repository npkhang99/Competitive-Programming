#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, a[109]={}, dp[109][50009]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        int m = 0;
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]), m+= a[i];
        int t = m; m /= 2;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(j-a[i] >= 0) dp[i][j] = max(dp[i-1][j-a[i]] + a[i], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
        printf("%d\n",abs((dp[n][m]) - (t-dp[n][m])));
    }
    return 0;
}
