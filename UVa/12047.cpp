#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 10009;

int n, m, p, s, t, d[2][N]={};
vector<ii> adj[N], rev[N];
vector<iii> edges;

void dijkstra(int s, vector<ii> adj[], int d[]){
    priority_queue<ii> q;
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second,
            du = -q.top().first;
        q.pop();
        if(du > d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first,
                dv = adj[u][i].second;
            if(du + dv <= p && du + dv < d[v]){
                d[v] = du + dv;
                q.push(ii(-d[v], v));
            }
        }
    }
}

void init(){
    edges.clear();
    for(int i=1; i<=n; i++){
        adj[i].clear();
        rev[i].clear();
    }
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
        init();
        while(m--){
            int x, y, v; scanf("%d %d %d", &x, &y, &v);
            adj[x].push_back(ii(y,v));
            rev[y].push_back(ii(x,v));
            edges.push_back(iii(ii(x,y), v));
        }

        memset(d, 0x3f, sizeof d);
        dijkstra(s, adj, d[0]);
        dijkstra(t, rev, d[1]);

        int ans = -1;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first.first,
                v = edges[i].first.second,
                c = edges[i].second;
            if(d[0][u] + c + d[1][v] <= p) ans = max(ans, c);
        }

        printf("%d\n", ans);
    }
    return 0;
}
