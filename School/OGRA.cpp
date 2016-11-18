#include <bits/stdc++.h>
using namespace std;

const int N = 300009;

int n, a[N]={}, c[N]={}, b[N]={};

int main(){
    // freopen("OGRA.inp","r",stdin);
    // freopen("OGRA.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&c[i]);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l = 1, r = n;
    for(int i=2; i<n; i++){
        if(c[i-1] < c[i] && c[i] > c[i+1]){
            b[i] = r--;
            // printf(" Up Peek: %d\n",i);
        }
    }
    if(c[1] > c[2]) b[1] = r--;
    if(c[n] > c[n-1]) b[n] = r--;
    for(int i=2; i<n; i++){
        if(c[i-1] > c[i] && c[i] < c[i+1]){
            b[i] = l++;
            // printf("Bot Peek: %d\n",i);
        }
    }
    if(c[1] < c[2]) b[1] = l++;
    if(c[n] < c[n-1]) b[n] = l++;
    for(int i=2; i<=n && l<=r; i++)
        if(!b[i] && c[i-1] > c[i]) b[i] = r--;
    for(int i=2; i<=n && l<=r; i++)
        if(!b[i] && c[i-1] < c[i]) b[i] = l++;

    // for(int i=1; i<=n; i++) printf("%d ",a[b[i]]); printf("\n");
    long long ans = 0;
    for(int i=1; i<n; i++)
        ans += (long long)abs(a[b[i]] - a[b[i+1]]);
    printf("%lld\n",ans);
    return 0;
}
