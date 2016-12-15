#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 1e5+9;

int n, m, par[N]={}, sz[N]={}, c[N]={}, _rank[N]={};
iii a[N]={};

int root(int p){ return p == par[p]? p:root(par[p]); }

void join(int u, int v){
    int x = root(u), y = root(v);
    if(x == y) return;
    if (_rank[x] > _rank[y]) { par[y] = x; sz[x] += sz[y]; }
    else{
        par[x] = y; sz[y] += sz[x];
        if (_rank[x] == _rank[y]) _rank[y]++;
    }
}

int main(){
    // freopen("DuongSat.inp","r",stdin);
    // freopen("DuongSat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int hq = 1e9;
    for(int i=1; i<=n; i++) scanf("%d",&c[i]), hq = min(hq,c[i]), par[i] = i;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
        a[i].first += a[i].first + c[a[i].second.first] + c[a[i].second.second];
    }
    sort(a,a+m);
    long long ans = hq, cnt = 0;
    for(int i=0; i<m; i++){
        int p = root(a[i].second.first), q = root(a[i].second.second);
        if(p == q) continue;
        join(p,q);
        ans += a[i].first;
        if(++cnt == n-1) break;
    }
    printf("%lld\n",ans);
    return 0;
}
