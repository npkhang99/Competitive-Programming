#include <bits/stdc++.h>
using namespace std;

const int N = 30009;

int n, m, par[N]={}, size[N]={}, set_rank[N]={};

int root(int p){
    return p == par[p]? p:root(par[p]);
}

int join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return size[u];
    if(set_rank[u] <= set_rank[v]){
        par[u] = v;
        size[v] += size[u];
        if(set_rank[u] == set_rank[v]) set_rank[v]++;
        return size[v];
    }
    par[v] = u;
    size[u] += size[v];
    return size[u];
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++){
            par[i] = i;
            size[i] = 1;
            set_rank[i] = 0;
        }

        int ans = 1;
        while(m--){
            int x, y; scanf("%d %d", &x, &y);
            ans = max(ans, join(x,y));
        }
        printf("%d\n", ans);
    }
    return 0;
}
