#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define Edge(x,y,z) iii(x,ii(y,z))

const int N = 1009;

int n, m, par[N]={}, ranking[N]={};
vector<iii> edges;

int root(int p){
    return p == par[p]? p:root(par[p]);
}

bool join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return false;
    if(ranking[u] <= ranking[v]){
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }else par[v] = u;
    return true;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        edges.push_back(Edge(z,x,y));
    }

    for(int i=1; i<=n; i++)
        par[i] = i;

    sort(edges.begin(), edges.end());
    int ans = 0, cnt = 0;
    for(int i = 0; i < m && cnt < n-1; i++){
        int u = edges[i].second.first,
            v = edges[i].second.second;
        if(join(u,v)){
            cnt++;
            ans = edges[i].first;
        }
    }

    printf("%d\n", ans);
    return 0;
}
