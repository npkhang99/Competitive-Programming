#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 259;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, b[N][N]={}, sh=0, wo=0;
char a[N][N];

inline int inrange(int x, int l, int r){ return l <= x && x < r; }

inline int canGo(int u, int v){
    return inrange(u,0,n) && inrange(v,0,m) && !b[u][v] && a[u][v] != '#';
}

void BFS(ii s){
    int cnt_s = 0, cnt_w = 0;
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1;
        if(a[u.x][u.y] == 'k') cnt_s += 1;
        if(a[u.x][u.y] == 'v') cnt_w += 1;
        for(int i=0; i<4; i++){
            ii v = ii(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y)) q.push(v);
        }
    }
    if(cnt_s > cnt_w) sh += cnt_s;
    else wo += cnt_w;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%s",&a[i]);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
        if(!b[i][j] && a[i][j] != '#')
            BFS(ii(i,j));
    printf("%d %d\n",sh,wo);
    return 0;
}
