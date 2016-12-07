#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

const int N=509;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int n, m, s1, s2, d1, d2, b[N][N]={};
char a[N][N];

void doc(){
    cin>> n>> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>> a[i][j];
            if(a[i][j]=='X') b[i][j]=1;
        }
    cin>> s1>> s2>> d1>> d2;
    s1-=1; s2-=1; d1-=1; d2-=1;
    b[d1][d2]=0;
}

int canGo(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void xuly(){
    for(int i=0; i<4; i++){
        int u=s1+dx[i], v=s2+dy[i];
        if(u==d1 && v==d2){
            int cnt=0;
            for(int i=0; i<4; i++){
                int u=d1+dx[i];
                int v=d2+dy[i];
                if(canGo(u,v) && a[u][v]=='.') cnt+=1;
            }
            if(cnt>0 || a[u][v]=='X'){
                printf("YES\n"); exit(0);
            }
        }
    }
    
    queue<int> qx,qy;
    qx.push(s1); qy.push(s2);
    while(!qx.empty()){
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        for(int i=0; i<4; i++){
            int u = x+dx[i];
            int v = y+dy[i];
            if(canGo(u,v) && !b[u][v]){
                b[u][v]=1;
                qx.push(u); qy.push(v);
                if(u==d1 && v==d2 && a[d1][d2]=='X'){
                    printf("YES\n");
                    exit(0);
                }
            }
        }
    }
    
    if(!b[d1][d2]){
        printf("NO\n"); exit(0);
    }
    int cnt=0;
    for(int i=0; i<4; i++){
        int u=d1+dx[i];
        int v=d2+dy[i];
        if(canGo(u,v) && a[u][v]=='.') cnt+=1;
    }
    if(cnt>1) printf("YES\n");
    else printf("NO\n");
}

int main(){
    doc();
    xuly();
    return 0;
}
