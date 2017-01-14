#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20009;

int n, a[N]={}, dp[N]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        memset(dp, 0, sizeof dp);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        int ans = 0;
        for(int i=0; i<n; i++){
            dp[a[i]] = max(dp[a[i]], dp[a[i]-1] + 1);
            ans = max(ans, dp[a[i]]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
