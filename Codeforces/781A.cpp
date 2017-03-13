#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, k = 1, a[N]={};
vector<int> adj[N];

void dfs(int u, int p){
    int c1 = a[p], c2 = a[u];

    if(c1 > c2) swap(c1, c2);
    int color = 1;
    for(int v : adj[u]){
        if(v == p) continue;
        if(color == c1) color++;
        if(color == c2) color++;
        k = max(k, color);
        a[v] = color++;
        dfs(v,u);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    a[0] = -1; a[1] = 1;
    dfs(1,0);

    printf("%d\n", k);
    for(int i=1; i<=n; i++)
        printf("%d%c", a[i], i==n? '\n':' ');
    return 0;
}
