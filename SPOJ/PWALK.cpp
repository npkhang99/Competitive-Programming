#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, m, par[N]={}, height[N]={};
vector<int> adj[N];
map<ii,long long> cost;

void dfs(int u, int h){
    height[u] = h;
    for(int v : adj[u]){
        if(par[v]) continue;
        par[v] = u;
        dfs(v, h+1);
    }
}

long long lca(int u, int v){
    if(u == v) return 0;
    if(height[u] == height[v])
        return cost[ii(u,par[u])] + cost[ii(v, par[v])] + lca(par[u], par[v]);
    if(height[u] > height[v])
        return cost[ii(u,par[u])] + lca(par[u], v);
    if(height[u] < height[v])
        return cost[ii(v,par[v])] + lca(u, par[v]);
    return 0;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<n; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[ii(x,y)] = cost[ii(y,x)] = z;
    }

    for(int i=1; i<=n; i++)
        par[i] = 0;

    par[1] = 1;
    dfs(1,1);

    while(m--){
        int x, y; scanf("%d%d", &x, &y);
        printf("%lld\n", lca(x,y));
    }
    return 0;
}
