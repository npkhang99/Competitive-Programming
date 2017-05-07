#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 30009;

int n, m, d[2][N]={}, memo[N]={};
vector<ii> adj[N];

void dijkstra(int s, int d[]){
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
            if(du + dv < d[v]){
                d[v] = du + dv;
                q.push(ii(-d[v], v));
            }
        }
    }
}

int check_multiple_routes(int u){
    if(u == n) return 1;
    if(memo[u] != -1) return memo[u];

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i].first,
            c = adj[u][i].second;
        if(d[0][u] + c + d[1][v] == d[0][n]){
            memo[u] += check_multiple_routes(v);
            if(memo[u] > 1) return memo[u];
        }
    }
    return memo[u];
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int x, y, v; scanf("%d %d %d", &x, &y, &v);
        adj[x].push_back(ii(y,v));
        adj[y].push_back(ii(x,v));
    }

    memset(d, 0x3f, sizeof d);
    memset(memo, -1, sizeof memo);
    dijkstra(1, d[0]);
    dijkstra(n, d[1]);

    if(check_multiple_routes(1) > 1){
        printf("%d\n", n-2);
        for(int i=2; i<n; i++)
            printf("%d\n", i);
        return 0;
    }

    vector<int> ans;
    for(int i=2; i<n; i++){
        if(d[0][i] + d[1][i] != d[0][n])
            ans.push_back(i);
    }

    printf("%d\n", ans.size());
    for(int i : ans)
        printf("%d\n", i);
    return 0;
}
