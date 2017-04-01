#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

int n, m, k, sz[N]={}, country[N]={}, edges_in[N]={}, separated=0;
vector<int> adj[N], govement;

void dfs(int u, int r){
    country[u] = r;
    edges_in[r] += adj[u].size();
    sz[r]++;
    separated++;

    for(int v : adj[u]){
        if(!country[v]){
            dfs(v,r);
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++){
        int x; scanf("%d", &x);
        govement.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x, y; scanf("%d %d", &x ,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int u : govement){
        dfs(u,u);
    }

    separated = n - separated;

    for(int gov : govement){
        edges_in[gov] /= 2;
    }

    int ans = 0, unused = 0, largest = govement[0];
    for(int gov : govement){
        if(sz[gov] > sz[largest]) largest = gov;
    }
    sz[largest] += separated;
    for(int i=1; i<=n; i++)
        if(!country[i]) unused += adj[i].size();
    unused /= 2;
    for(int gov : govement){
        ans += sz[gov]*(sz[gov]-1) / 2 - edges_in[gov];
    }

    printf("%d\n", ans - unused);
    return 0;
}
