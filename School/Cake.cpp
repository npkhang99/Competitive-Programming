#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, a[N]={}, d[N]={};
long long ans = 0;
vector<int> adj[N];
set<int> b;

void dfs(int u, int c, int p1=0, int p2=0){
    b.erase(u); d[u] = 1;
    for(int v : adj[u]){
        if(v == p2){
            fprintf(stderr, "%d %d %d\n", p2, p1, u);
            ans += max(a[u], max(a[p1], a[p2]));
            continue;
        }
        if(!d[v]) dfs(v, c+1, u, p1);
    }
}

int main(){
#ifdef THEMIS
    freopen("Cake.inp","r",stdin);
    freopen("Cake.out","w",stdout);
#endif // THEMIS
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    while(m--){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
        b.insert(i);

    while(!b.empty()){
        int u = *b.begin();
        dfs(u, 5);
    }

    printf("%lld\n", ans);
    return 0;
}
