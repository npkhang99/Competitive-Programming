#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 500009;

int n, k, c[N]={}, b[N]={};
long long memo[N]={};
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
    if(b[u]) return;
    trace(u);
}

long long dist(int u){
    if(memo[u] != -1) return memo[u];
    return memo[u] = dist(pr[u].first) + pr[u].second;
}

int main(){
    // freopen("KAMP02.inp","r",stdin);
    // freopen("KAMP02.out","w",stdout);
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
    memset(memo, -1, sizeof memo);
    b[c[0]] = true;
    for(int i=1; i<k; i++)
        trace(c[i]);

    for(int i=1; i<=n; i++)
        if(b[i]) memo[i] = 0;

    for(int i=1; i<=n; i++)
        printf("%lld\n",dist(i));
    return 0;
}
