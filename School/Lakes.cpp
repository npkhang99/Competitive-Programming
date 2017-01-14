#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 59;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

int n, m, k, b[N][N]={}, flag[N*N]={};
char a[N][N]={};
ii sz[N*N];

int canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m && !b[u][v] && a[u][v] == '.';
}

int BFS(ii s, int flag){
    queue<ii> q;
    int cnt = 0;
    q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = flag; cnt += 1;
        for(int i=0; i<4; i++){
            ii v(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y))
                q.push(v);
        }
    }
    return cnt;
}

int main(){
    // freopen("Lakes.inp","r",stdin);
    // freopen("Lakes.out","w",stdout);
    scanf("%d %d %d ",&n,&m,&k);
    for(int i=0; i<n; i++)
        scanf("%s",a[i]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(a[i][j] == '*')
                b[i][j] = -1;
            if(a[i][j] == '.' && (i == 0 || i == n-1 || j == 0 || j == m-1))
                BFS(ii(i,j),-1);
        }

    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] == '.' && !b[i][j]){
                sz[cnt] = ii(BFS(ii(i,j),cnt+1),cnt+1);
                cnt += 1;
            }

    sort(sz,sz+cnt);
    int fill = 0, l = 0;
    for(l = 0; cnt - l > k; fill+=sz[l++].first)
        flag[sz[l].second] = 1;
    
    printf("%d\n",fill);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            if(flag[b[i][j]]) printf("*");
            else printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
