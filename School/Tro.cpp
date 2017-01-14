#include <bits/stdc++.h>
using namespace std;

const int N = 300009;

struct Line{
    int a,b,c;
}a[N];

int n;

int comp(Line a, Line b){
    return a.a*b.b < b.a*a.b;
}

int main(){
    // freopen("Tro.inp","r",stdin);
    // freopen("Tro.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
    sort(a,a+n,comp);
    long long ans = 0, l = 1, r = 1;
    while(r < n){
        while(r < n && a[l].a * a[r].b == a[r].a * a[l].b) r++;
        ans = (ans + (l) * (r-l) * (n-r)) % 1000000007;
        l = r;
    }
    printf("%lld\n",ans);
    return 0;
}
