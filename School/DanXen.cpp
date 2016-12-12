#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, a[N]={}, b[N]={}, dp[N]={};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("DanXen.inp","r",stdin);
    // freopen("DanXen.out","w",stdout);
    // scanf("%d",&n);
    cin>> n;
    for(int i=0; i<n; i++)
        // scanf("%d",&a[i]);
        cin>> a[i];
    for(int i=0; i<n; i++)
        cin>> b[i]// scanf("%d",&b[i])
        , dp[i] = -1e9;

    int ans = -1e9, mb = 0, mw = 0;
    for(int i=0; i<n; ans = max(ans,dp[i++])){
        if(b[i] == 1){
            dp[i] = max(dp[i], mw + a[i]);
            mb = max(mb,dp[i]);
            continue;
        }
        dp[i] = max(dp[i], mb + a[i]);
        mw = max(dp[i],mw);
    }
    // printf("%d\n", ans);
    cout<< ans<< '\n';
    return 0;
}
