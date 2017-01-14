#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, k, a[N]={}, L[N]={}, R[N]={}, ans = 10E8;

int f(int l, int r){
    return a[r] - a[l] + a[l+1] - a[l];
}

int main(){
    // freopen("DiffNum.inp","r",stdin);
    // freopen("DiffNum.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++) printf("%3d ",a[i]); printf("\n");
    for(int i=1; i<=n+1; i++)
        if(a[i-1] != a[i]) R[i-1] = i;
        else R[i] = R[i-1];
    for(int i=n; i>0; i--)
        if(a[i+1] != a[i]) L[i+1] = i;
        else L[i] = L[i+1];

    // for(int i = 1; i <= n; i++) printf("%3d ",R[i]); printf("\n");
    // for(int i = 1; i <= n; i++) printf("%3d ",L[i]); printf("\n");

    int i = 1, j = n, cnt = 0;
    while(cnt - k){
        
    }
    return 0;
}
