#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N=1009;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int T, n, m, a[N][N]={}, d[N][N]={};

int canGo(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dijkstra(){
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(a[0][0],ii(0,0))); d[0][0] = a[0][0];
    while(!q.empty()){
        int x = q.top().second.first, y = q.top().second.second, du = q.top().first; q.pop();
        if(du > d[x][y]) continue;
        for(int i=0; i<4; i++){
            int u = x+dx[i], v = y+dy[i];
            if(canGo(u,v) && d[u][v] > d[x][y] + a[u][v])
                d[u][v] = d[x][y]+a[u][v], q.push(iii(d[u][v],ii(u,v)));
        }
    }
    printf("%d\n",d[n-1][m-1]);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]), d[i][j] = 10E8;
        dijkstra();
    }
    return 0;
}
