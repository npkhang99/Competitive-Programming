#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=709;
const int dx[] = {-1,-1,-1,0,1,1,1,0};
const int dy[] = {-1,0,1,1,1,0,-1,-1};

int n, m, a[N][N], b[N][N]={};

int canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m;
}

void DFS(int x, int y, int s){
    b[x][y] = 1;
    for(int i=0; i<8; i++){
        int u = x+dx[i], v = y+dy[i];
        if(canGo(u,v) && !b[u][v] && a[u][v]<=a[x][y] && a[u][v] < s) DFS(u,v,s);
    }
}

void markConnectedComponent(int x, int y){
    b[x][y] = 1;
    for(int i=0; i<8; i++){
        int u = x+dx[i], v = y+dy[i];
        if(canGo(u,v) && !b[u][v]) markConnectedComponent(u,v);
    }
}

int main(){
    // freopen("NKGUARD.inp","r",stdin);
    // freopen("NKGUARD.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) scanf("%d",&a[i][j]);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!b[i][j]) DFS(i,j,a[i][j]), b[i][j] = 0;

    int k = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!b[i][j]) markConnectedComponent(i,j), k++;

    printf("%d\n",k);
    return 0;
}
