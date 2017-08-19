#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, k, q;
long long dist[N]={};
vector<ii> adj[N];

void dfs(int u, long long length){
    dist[u] = length;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first,
            dv = adj[u][i].second;
        if(!~dist[v]) dfs(v, length + dv);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int x, y, v; scanf("%d %d %d", &x, &y, &v);
        adj[x].push_back({y,v});
        adj[y].push_back({x,v});
    }

    memset(dist, -1, sizeof dist);

    scanf("%d %d", &q, &k);
    dfs(k,0);

    for(int i = 0; i < q; i++){
        int x, y; scanf("%d %d", &x, &y);
        printf("%lld\n", dist[x] + dist[y]);
    }
    return 0;
}
