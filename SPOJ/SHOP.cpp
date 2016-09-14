// SPOJ submission 17395992 (C++ 5) plaintext list. Status: AC, problem SHOP, contest SPOJ. By mansblacks (Khang), 2016-07-30 06:31:23.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int N=29;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int n, m, a[N][N]={}, L[N][N]={}, b[N][N]={}, s1, s2, d1, d2;

void doc(){
    char c;
    cin>> m>> n;
    if(n==0 && m==0) exit(0);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>> c;
            if(c=='S'){ s1=i; s2=j; }
            else if(c=='D'){ d1=i; d2=j; }
            a[i][j] = int(c)-48; L[i][j] = 10E8;
            if(c=='X') b[i][j]=1;
            else b[i][j]=0;
        }
    L[s1][s2] = 0;
    a[s1][s2] = 40;
    a[d1][d2] = 0;
}

int canGo(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && a[x][y]!=40;
}

void xuly(){
    queue<int> qx,qy;
    qx.push(s1); qy.push(s2);
    while(!qx.empty()){
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        for(int i=0; i<4; i++){
            int u = x+dx[i];
            int v = y+dy[i];
            if(canGo(u,v) && a[u][v]+L[x][y]<L[u][v]){
                qx.push(u);
                qy.push(v);
                L[u][v]=L[x][y]+a[u][v];
            }
        }
    }
    printf("%d\n",L[d1][d2]);
}

int main(){
    while(true){
        doc();
        xuly();
    }
    return 0;
}
