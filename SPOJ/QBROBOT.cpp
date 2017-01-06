#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii>  iii;
typedef pair<int,iii> iiii;

inline iiii pp(int x, int y, int z, int t){ return iiii(x, iii(y, ii(z,t))); }
inline iii pp(int y, int z, int t){ return iii(y, ii(z,t)); }

#define maxFuel second.second
#define fuel second.first
#define time first

const int N = 509;

int n, m, t[N][N]={}, c[N][N]={}, d[N]={}, station[N]={}, need;
vector<int> a[N];

int dijkstra(int src, int dest){
    priority_queue<ii> q; q.push(ii(0,src));
    for(int i=1; i<=n; i++) d[i] = 1e9;
    d[src] = 0;
    while(!q.empty()){
        int u = q.top().second,
            du = -q.top().first;
        q.pop();
        if(d[u] < du) continue;
        if(u == dest) return du;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i];
            if(d[v] > du + t[u][v]){
                d[v] = du + t[u][v];
                q.push(ii(-d[v],v));
            }
        }
    }
}

void bfs(){
    queue<iiii> q; q.push(pp(1,0,0,0));
    int ans = 1e9;
    while(!q.empty()){
        int u = q.front().first;
        iii du = q.front().second;
        q.pop();
        if(du.time + d[u] > need || (du.time == need && u != n)) continue;
        if(u == n){
            ans = min(ans, du.maxFuel);
            continue;
        }

        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i], f = du.fuel + c[u][v];
            iii dv = pp(du.time + t[u][v], f * (1 - station[v]), max(f, du.maxFuel));
            if(dv.time <= need && dv.maxFuel < ans) q.push(iiii(v,dv));
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d", &station[i]);
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d%d",&x,&y);
        scanf("%d%d", &t[x][y], &c[x][y]);
        t[y][x] = t[x][y]; c[y][x] = c[x][y];
        a[x].push_back(y);
        a[y].push_back(x);
    }
    need = dijkstra(n,1);
    bfs();
    return 0;
}
