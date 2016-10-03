#include <stdio.h>
using namespace std;

const int N=10009;

int n, a[N]={}, dp[N]={};

int main(){
    // freopen("SEQ.inp","r",stdin);
    // freopen("SEQ.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    int ans = 1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=i-1; j>=0; j--)
            if(a[i]%a[j]==0) dp[i] = dp[i]<dp[j]+1? dp[j]+1:dp[i];
        ans = ans<dp[i]? dp[i]:ans;
    }
    printf("%d\n",ans);
    return 0;
}
