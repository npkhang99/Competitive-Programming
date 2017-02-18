#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, color[N];
bool visited[N]={};
vector<int> adj[N];

bool dfs(int u, int color){
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v])
            if(color != ::color[v] || !dfs(v,color)){
                return false;
            }

    return true;
}

bool check(int root){
    memset(visited, false, sizeof visited);
    visited[root] = true;
    for(int child : adj[root])
        if(!dfs(child, color[child])) return false;

    return true;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n-1; i++){
        int x, y; scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        scanf("%d", &color[i]);

    int p1 = 0, p2 = 0;
    for(int u=1; u<=n; u++){
        for(int v : adj[u])
            if(color[u] != color[v]){
                p1 = u;
                p2 = v;
                break;
            }
        if(p1) break;
    }

    if(!p1){
        printf("YES\n1\n");
        return 0;
    }

    int ans = 0;
    if(check(p1)) ans = p1;
    else if(check(p2)) ans = p2;

    if(ans) printf("YES\n%d\n", ans);
    else printf("NO\n");
    return 0;
}
