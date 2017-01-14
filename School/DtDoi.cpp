#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, a[N], S, dp[109] = {};

int main(){
    // freopen("DtDoi.inp","r",stdin);
    // freopen("DtDoi.out","w",stdout);
    scanf("%d%d",&n,&S);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int ans = INT_MAX;
    for(int ll=0; ll<n; ll++){
        int l = S / a[ll], s = S % a[ll];
        for(int i=0; i<109; i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i=0; i<s; i++)
            if(dp[i] != INT_MAX)
                for(int j=0; j<n; j++)
                    dp[i+a[j]] = min(dp[i+a[j]], dp[i] + 1);
        ans = min(ans,dp[s]+l);
    }
    printf("%d\n",ans);
    return 0;
}
