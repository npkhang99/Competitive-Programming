#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define x first
#define y second

const int N = 109;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, a[N][N]={}, d[N][N]={};

bool canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m;
}

int dijkstra(ii s){
    priority_queue<iii> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            d[i][j] = 10E8;

    q.push(iii(-a[s.x][s.y],s)); d[s.x][s.y] = a[s.x][s.y];
    while(!q.empty()){
        int du = -q.top().first;
        ii u = q.top().second;
        q.pop();
        if(du > d[u.x][u.y]) continue;
        if(u.y == m-1) return du;
        for(int i=0; i<4; i++){
            ii v(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y) && d[v.x][v.y] > du + a[v.x][v.y]){
                d[v.x][v.y] = du + a[v.x][v.y];
                q.push(iii(-d[v.x][v.y],v));
            }
        }
    }
}

int main(){
    // freopen("Fair.inp","r",stdin);
    // freopen("Fair.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);

    int ans = 10E8;
    for(int i=0; i<n; i++){
        // printf("%d\n",dijkstra(ii(i,0)));
        ans = min(ans,dijkstra(ii(i,0)));
    }
    printf("%d\n",ans);
    return 0;
}
