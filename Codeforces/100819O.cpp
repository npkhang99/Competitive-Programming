#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int N=509;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, b[N][N]={};
char a[N][N];

int canGo(int u, int v){
    return u>=0 && u<n && v>=0 && v<m && !b[u][v];
}

void BFS(){
    queue<int> qx, qy, qz;
    qx.push(0); qy.push(0); qz.push(0);
    while(!qx.empty()){
        int x = qx.front(), y = qy.front(), z = qz.front();
        qx.pop(); qy.pop(); qz.pop();
        if(b[x][y]) continue;
        if(x==n-1 && y==m-1){
            printf("%d\n",z);
            return;
        }
        b[x][y] = 1;
        for(int i=0; i<4; i++){
            int u = x+dx[i]*(a[x][y]-48), v = y+dy[i]*(a[x][y]-48);
            if(canGo(u,v))
                qx.push(u), qy.push(v), qz.push(z+1);
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    scanf("%d%d\n",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s\n",a[i]);
    BFS();
    return 0;
}
