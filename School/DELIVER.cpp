#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;

const int N=59;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

struct pos{
    int x, y, c1, c2, direct;
}curr;

int n=0, L[N][N][2][2][4]={}, b[N][N][2][2][4]={}, s=0, t=0, x1=-1, y1=0, x2=0, y2=0;
string a[N];

int inrange(int u,int a,int b){ return u>=a && u<b; }

int canGo(int u, int v, int c1, int c2, int direct){
    return (a[u][v]=='C' || a[u][v]=='.') && !b[u][v][c1][c2][direct] && inrange(u,0,n) && inrange(v,0,a[0].size());
}

int main(){
    // freopen("deliver.in","r",stdin);
    // freopen("deliver.out","w",stdout);
    while(cin>> a[n]){
        if(s){ n+=1; continue; }
        for(int i=0; i<a[n].size(); i++){
            if(a[n][i]=='S'){ s=n; t=i; break; }
            if(a[n][i]=='C' && x1==-1){ x1=n; y1=i; break; }
            x2=n; y2=i; break;
        }
        n+=1;
    }
    curr.x = s; curr.y = t; curr.c1 = curr.c2 = 0; curr.direct = -1;
    b[s][t][0][0][0] = b[s][t][0][0][1] = b[s][t][0][0][2] = b[s][t][0][0][3] = 1;
    queue<pos> q;
    q.push(curr);
    pos next;
    while(!q.empty()){
        curr = q.front(); q.pop();
        for(int i=0; i<4; i++){
            if(i==curr.direct) continue;
            int u = curr.x + dx[i],
                v = curr.y + dy[i];
            if(canGo(u,v,curr.c1,curr.c2,i)){
                L[u][v][curr.c1][curr.c2][i] = L[curr.x][curr.y][curr.c1][curr.c2][curr.direct]+1;
                next.x = u; next.y = v; next.c1 = curr.c1; next.c2 = curr.c2; next.direct = i;
                if(u==x1 && v==y1) next.c1 = 1;
                if(u==x2 && v==y2) next.c2 = 1;
                L[u][v][next.c1][next.c2][next.direct] = L[curr.x][curr.y][curr.c1][curr.c2][curr.direct] + 1;
                b[u][v][next.c1][next.c2][next.direct] = 1;
                if(next.c1==1 && next.c2==1){
                    printf("%d\n",L[u][v][next.c1][next.c2][next.direct]);
                    exit(0);
                }
                q.push(next);
            }
        }
    }
    printf("-1\n");
    return 0;
}
