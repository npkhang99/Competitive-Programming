#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, m;
ii a[N]={};

int main(){
    // freopen("Thief.inp","r",stdin);
    // freopen("Thief.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n+1);
    long long ans = 0;
    for(int i=1; i<=n; i++)
        ans += max(0, a[i].second - a[i-1].second);
    printf("%lld\n", ans);
    return 0;
}
