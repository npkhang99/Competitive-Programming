#include <bits/stdc++.h>
using namespace std;

const int N = 2009;

int n_left, n_right, m, match[N]={};
bool visited[N]={};
vector<int> adj[N];

int augmenting_path(int u){
    if(visited[u]) return 0;
    visited[u] = true;
    for(int v : adj[u]){
        if(match[v] == -1 || augmenting_path(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d %d", &n_left, &n_right, &m);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d %d", &x, &y);
        y += n_left;
        adj[x].push_back(y);
    }

    int ans = 0;
    memset(match, -1, sizeof match);
    for(int i=1; i<=n_left; i++){
        memset(visited, false, sizeof visited);
        ans += augmenting_path(i);
    }

    printf("%d\n", ans);
    return 0;
}
