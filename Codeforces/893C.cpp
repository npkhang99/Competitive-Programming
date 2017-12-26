#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, a[N]={}, visited[N]={};
vector<int> adj[N];

int dfs(int u, int x){
    visited[u] = true;
    for(int v : adj[u]){
        if(visited[v]) continue;
        x = dfs(v, min(x, a[v]));
    }
    return x;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while(m--){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        ans += dfs(i, a[i]);
    }

    printf("%lld\n", ans);
    return 0;
}
