#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, k;
long long a[N]={}, b[N]={}, d[N]={};

int main(){
    // freopen("Product.inp","r",stdin);
    // freopen("Product.out","w",stdout);
    scanf("%d%d\n",&n,&k);
    for(int i=0; i<n; i++) scanf("%I64d",&a[i]);
    for(int i=0; i<k; i++) scanf("%I64d",&b[i]);
    
    d[0]=a[0];
    for(int i=1; i<n; i++) d[i] = d[i-1]+a[i];
    
    for(int i=0; i<k; i++){
        int vt = upper_bound(a,a+n,b[i])-a;
        long long ans = d[vt-1]+b[i]*(n-vt);
        printf("%I64d ",ans);
    }
    printf("\n");
    return 0;
}