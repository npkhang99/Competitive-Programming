#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={}, lis[N]={}, lds[N]={}, b[N]={};

void LIS(int L[]){
    int m = 0;
    memset(b, 0, sizeof b);
    for(int i=1; i<=n; i++){
        L[i] = lower_bound(b+1, b+m+1, a[i]) - b;
        m = max(m, L[i]);
        b[L[i]] = a[i];        
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);

    LIS(lis);
    reverse(a+1, a+n+1);
    LIS(lds);

    int ans = 1;
    for(int i=1; i<=n; i++)
        ans = max(ans, min(lis[i], lds[n-i+1])*2 - 1);

    printf("%d\n", ans);
    return 0;
}
