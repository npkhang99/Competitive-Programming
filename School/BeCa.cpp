#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 309;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, a[N][N]={}, b[N][N]={};
char c[N][N]={};

void trans(int u, int v, int dx, int dy){
    a[u][v] = a[u+dx][v+dy] = a[u+2*dx][v+2*dy] = 1;
    b[u][v] = b[u+dx][v+dy] = b[u+2*dx][v+2*dy] = 1;
}

bool canGo(int u, int v){
    return 0 <= u && u < 3*n && 0 <= v && v < 3*m && !a[u][v] && !b[u][v];
}

int BFS(ii s){
    queue<ii> q;
    int cnt = 0;
    q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1; cnt += 1;
        for(int i=0; i<4; i++){
            ii v(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y))
                q.push(v);
        }
    }
    return cnt;
}

int main(){
    // freopen("BeCa.inp","r",stdin);
    // freopen("BeCa.out","w",stdout);
    scanf("%d%d ",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s ",c[i]);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            // printf("%c\n",c[i][j]);
            if(c[i][j] == '\\') trans(i*3,j*3,1,1);
            else trans(i*3,j*3+2,1,-1);
        }

    // for(int i=0; i<3*n; i++){
    //     for(int j=0; j<3*m; j++)
    //         printf("%c ",!b[i][j]? ' ':char(b[i][j]+48));
    //     printf("\n");
    // }printf("\n");

    for(int i=0; i<3*n; i++){
        if(!b[i][0]) BFS(ii(i,0));
        if(!b[i][3*m-1]) BFS(ii(i,3*m-1));
    }
    for(int i=0; i<3*m; i++){
        if(!b[0][i]) BFS(ii(0,i));
        if(!b[3*n-1][i]) BFS(ii(3*n-1,i));
    }

    // for(int i=0; i<3*n; i++){
    //     for(int j=0; j<3*m; j++)
    //         printf("%c ",!b[i][j]? ' ':char(b[i][j]+48));
    //     printf("\n");
    // }printf("\n");

    int ans = 0, cnt = 0;
    for(int i=0; i<3*n; i++)
        for(int j=0; j<3*m; j++)
            if(!b[i][j])
                // printf("%d %d - %d %d\n",i,j,a[i][j],b[i][j]),
                cnt += 1, ans = max(ans,BFS(ii(i,j)));
    printf("%d\n%d\n",cnt,ans/6);
    return 0;
}
