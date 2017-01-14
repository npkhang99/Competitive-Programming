#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 500009;

int n, k, c[N]={}, b[N]={};
long long ans = 0;
ii pr[N]={};
vector<ii> a[N];

void DFS(int u){
    b[u] = true;
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].first;
        if(!b[v]){
            pr[v] = ii(u,a[u][i].second);
            DFS(v);
        }
    }
}

void trace(int v){
    int u = pr[v].first;
    b[v] = true;
    ans += pr[v].second;
    if(b[u]) return;
    trace(u);
}

int main(){
    // freopen("KAMP01.inp","r",stdin);
    // freopen("KAMP01.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<n; i++){
        int x, y, v; scanf("%d%d%d",&x,&y,&v);
        a[x].push_back(ii(y,v));
        a[y].push_back(ii(x,v));
    }
    for(int i=0; i<k; i++)
        scanf("%d",&c[i]);

    DFS(c[0]);
    memset(b, false, sizeof b);
    b[c[0]] = true;
    for(int i=1; i<k; i++)
        trace(c[i]);
    printf("%lld\n",ans);
    return 0;
}
