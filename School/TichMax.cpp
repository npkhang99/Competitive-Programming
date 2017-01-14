#include <bits/stdc++.h>
using namespace std;

const int N=1000009;

int n, a[N]={};

int main(){
    // freopen("TichMax.inp","r",stdin);
    // freopen("TichMax.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",max(a[n-1]*a[n-2]*a[n-3], a[0]*a[1]*a[n-1]));
    return 0;
}
