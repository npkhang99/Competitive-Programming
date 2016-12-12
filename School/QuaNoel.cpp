#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int,int> ii;   // position: x, y
typedef pair<int,ii> cost;  // cost: Total cost + (min,max)
typedef pair<cost,int> pos; // curr: cost + visited
typedef pair<pos,ii> state; // pos + position

#define fi first
#define se second

#define x first
#define y second

const int N = 109;
const int dx[] = {-1,-1,-1,0,1,1,1,0};
const int dy[] = {-1,0,1,1,1,0,-1,-1};

int n, m, a[N][N]={}, cnt = 0, d[N][N][N*N]={};
char c[N][N]={};
ii s;
map<cost,cost> tr;
map<cost,bool> b;

bool canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m;
}

int f(ii u){
    return u.y - u.x;
}

void trace(cost i){
    if(i.se != s) trace(tr[i]);
    printf("%d %d - %d\n", i.se.fi,i.se.se,i.fi);
}

int dijkstra(int sth){
    priority_queue<state> q;
    q.push(state(
        pos(
            cost(0, ii(sth,sth)),
            0
        ),
        s
    ));

    while(!q.empty()){
        ii u = q.top().se;
        int du = -q.top().fi.fi.fi;
        int visited = q.top().fi.se, lo = q.top().fi.fi.se.fi, hi = q.top().fi.fi.se.se;
        q.pop();
        if(du > d[u.x][u.y][visited]) continue;
        printf("\n(%d %d) cost %d - visited %d - %d %d\n", u.x, u.y, du, visited, lo, hi);
        if(visited == cnt){
            trace(cost(visited,u));
            return du;
        }
        for(int i=0; i<8; i++){
            ii v(u.x + dx[i], u.y + dy[i]);
            ii _(min(lo, a[v.x][v.y]), max(hi, a[v.x][v.y]));
            int nv = visited;
            if(c[v.x][v.y] == 'K' && !b[cost(nv+1,v)]);
            if(canGo(v.x,v.y) && d[v.x][v.y][nv] > f(_)){
                printf("\t(%d %d) cost %d - visited %d\n", v.x, v.y, f(_), nv);
                d[v.x][v.y][nv] = f(_);
                // tr[v.x][v.y][nv] = cost(visited,u);
                tr[cost(nv,v)] = cost(visited,u);
                q.push(state(
                    pos(
                        cost(
                            -d[v.x][v.y][nv],
                            _
                        ),
                        nv
                    ),
                    v
                ));
            }
        }
    }
}

int main(){
    // freopen("QuaNoel.inp","r",stdin);
    // freopen("QuaNoel.out","w",stdout);
    scanf("%d%d ",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s ",c[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(c[i][j] == 'P') s = ii(i,j);
            if(c[i][j] == 'K') cnt += 1;
            scanf("%d",&a[i][j]);
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<=cnt; k++)
                d[i][j][k] = 2e9;
    d[s.x][s.y][0] = 0;
    // printf("%d\n", cnt);
    printf("%d\n",dijkstra(a[s.x][s.y]));
    return 0;
}
