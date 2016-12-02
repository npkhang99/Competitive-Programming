#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<ll,ll> ii;

const int N = 500009;

int n, k, c[N]={}, b[N]={};
long long memo[N]={}, temp[N]={};
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

long long dist(int u){
    if(memo[u] != -1) return memo[u];
    return memo[u] = dist(pr[u].first) + pr[u].second;
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
        // if(tr[u] > 0) continue;
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

int main(){
    freopen("KAMP03.inp","r",stdin);
    freopen("KAMP03.out","w",stdout);
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
    memset(memo, -1, sizeof memo);
    b[c[0]] = true;
    for(int i=1; i<k; i++)
        trace(c[i]);

    // for(int i=1; i<=n; i++){
    //     fprintf(stderr,"%d - %7s -", i, b[i]? "Pick":"No pick");
    //     for(int j=0; j<g[i].size(); j++)
    //         fprintf(stderr," (%d - %d)", g[i][j].first, g[i][j].second);
    //     fprintf(stderr, "\n");
    // }
    // fprintf(stderr, "\n");
    bfs(c[0],0);

    // for(int i=0; i<t.size(); i++)
    //     fprintf(stderr, "(%d - %d)%c", t[i].first, t[i].second, i == t.size()-1? '\n':' ');

    for(int i=1; i<t.size(); i++)
        temp[i] = temp[i-1] + t[i].second;

    memo[t[0].first] = t.back().second;
    for(int i=1; i<t.size(); i++)
        memo[t[i].first] = max(t[i].second, t.back().second - temp[i]);

    for(int i=1; i<=n; i++)
        if(!b[i]) memo[i] = 0;

    for(int i=1; i<=n; i++)
        printf("%lld\n",dist(i));
    return 0;
}
