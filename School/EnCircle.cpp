#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N=109;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, ans=0, b[N][N]={}, d[N][N]={};
char a[N][N];

inline int inrange(int x, int l, int r){ return l <= x && x < r; }
inline int canGo(int u, int v){
    return inrange(u,0,n) && inrange(v,0,n) && !b[u][v];
}

void BFS(ii s){
    int cnt_free = 0, cnt = 0;
    vector<ii> freeSpot;
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1; cnt += 1;
        for(int i=0; i<4; i++){
            ii v = ii(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y) && a[v.x][v.y] == 'w') q.push(v);
            if(canGo(v.x,v.y) && a[v.x][v.y] == '.')
                cnt_free += 1, b[v.x][v.y] = 1, freeSpot.push_back(v);
        }
    }
    if(cnt_free == 1)
        ans = max(ans,cnt + d[freeSpot[0].x][freeSpot[0].y]),
        d[freeSpot[0].x][freeSpot[0].y] = cnt;
    for(int i=0; i<freeSpot.size(); i++) b[freeSpot[i].x][freeSpot[i].y] = 0;
}

int main(){
    // freopen("EnCircle.inp","r",stdin);
    // freopen("EnCircle.out","w",stdout);
    while(~scanf("%d",&n)){
        ans = 0; memset(b,0,sizeof(b)); memset(d,0,sizeof(d));
        for(int i=0; i<n; i++) scanf("%s",a[i]);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++)
            if(a[i][j] == 'b') b[i][j] = 1;

        for(int i=0; i<n; i++) for(int j=0; j<n; j++)
            if(a[i][j] == 'w' && !b[i][j]) BFS(ii(i,j));
        printf("%d\n",ans);
    }
    return 0;
}
