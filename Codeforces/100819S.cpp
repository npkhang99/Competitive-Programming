#include <bits/stdc++.h>
using namespace std;

const int N = 300009;

struct wave{
    int m, f, w;
}a[N]={};

int n;
long long dp[10*N]={};

int comp(wave a, wave b){
    return a.m < b.m;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &a[i].m, &a[i].f, &a[i].w);
    sort(a,a+n,comp);

    long long c = 0;
    for(int i=a[0].m, j=0; i<=a[n-1].m; i++){
        c = max(dp[i],c);
        while(j < n && i == a[j].m){
            dp[i+a[j].w] = max(dp[i+a[j].w], c + a[j].f);
            j++;
        }
    }

    long long ans = 0;
    for(int i=1; i<=(int)2e6; i++)
        ans = max(ans,dp[i]);
    printf("%lld\n",ans);
    return 0;
}
