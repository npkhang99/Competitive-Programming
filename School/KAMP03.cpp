#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<ll,ll> ii;

const int N = 500009;

int n, k, c[N]={}, b[N]={}, _b[N]={};
long long dist[N]={};
ii pr[N]={}, tr[N]={};
vector<ii> a[N], g[N], t;

void DFS(int u){
    b[u] = true;
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].first;
        if(!b[v]){
            pr[v] = ii(u,a[u][i].second);
            DFS(v);
        }
    }
}

void trace(int v){
    int u = pr[v].first;
    b[v] = true;
    g[u].push_back(ii(v,pr[v].second));
    g[v].push_back(ii(u,pr[v].second));
    if(b[u]) return;
    trace(u);
}

void tracePath(ii i){
    if(tr[i.first].first > 0) tracePath(tr[i.first]);
    t.push_back(ii(i.first,i.second));
}

void bfs(int s, int l){
    queue<ii> q;
    for(int i=1; i<=n; i++) tr[i] = ii(0,0);
    int last = s, temp = 0;
    q.push(ii(s,0)); tr[s] = ii(-1,0);
    while(!q.empty()){
        int u = q.front().first, du = q.front().second; q.pop();
        if(du > temp) last = u, temp = du;
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i].first;
            if(!tr[v].first){
                tr[v] = ii(u,du);
                q.push(ii(v, du + g[u][i].second));
            }
        }
    }

    if(last == l) tracePath(ii(last,temp));
    else bfs(last,s);
}

void dfs(int u, long long d){
    dist[u] = d;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i].first;
        if(dist[v] == -1) dfs(v,d+g[u][i].second);
    }
}

int main(){
    // freopen("KAMP03.inp","r",stdin);
    // freopen("KAMP03.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<n; i++){
        int x, y, v; scanf("%d%d%d",&x,&y,&v);
        a[x].push_back(ii(y,v));
        a[y].push_back(ii(x,v));
    }
    for(int i=0; i<k; i++)
        scanf("%d",&c[i]);

    DFS(c[0]);
    memset(b, false, sizeof b);
    memset(dist, -1, sizeof dist);
    b[c[0]] = true;
    for(int i=1; i<k; i++)
        trace(c[i]);

   bfs(c[0],0);

   dist[t[0].first] = t.back().second;
    for(int i=1; i<t.size(); i++)
        dist[t[i].first] = max(t[i].second, t.back().second - t[i].second);

    for(int i=1; i<=n; i++)
        if(!b[i]) dist[i] = 0;

    for(int i=0; i<t.size(); i++)
        dfs(t[i].first,dist[t[i].first]);

    for(int i=1; i<=n; i++)
        printf("%lld\n",dist[i]);
    return 0;
}
