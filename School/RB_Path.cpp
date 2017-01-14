#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
#define inf INT_MAX
#define for(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int n, a[2000][2000];
bool c[2000][2000];
//---------------------------------------------------------
void doc(){
    int m, x, y, t1, t2;
    cin>> n>> m;
    for(i,1,n)
        for(j,1,n){
            if (i==j) a[i][j]=0;
            else a[i][j]=inf;
        }
    for(i,1,m){
        cin>> x>> y>> t1>> t2;
        a[y][x]=a[x][y]=t1;
        if (t2==1) c[x][y]=c[y][x]=true;
        else c[x][y]=c[y][x]=false;
    }
}
//---------------------------------------------------------
int dijkstra(){
    int L[2000], u, Lmin;
    bool b[2000], tt[2000];
    memset(b,0,sizeof(b));
    for(i,1,n){
        L[i]= a[1][i];
        tt[i]= c[1][i];
    }
    b[1]=true;
    do{
        Lmin=inf; u=0;
        for(i,1,n)
            if (!b[i] && L[i]<Lmin){
                Lmin=L[i];
                u=i;
            }
        if (u==0) return -1;
        for(v,1,n)
            if (!b[v] && a[u][v]<inf && L[v]>L[u]+a[u][v] && c[u][v]!=tt[u]){
                L[v]=L[u]+a[u][v];
                tt[v]=c[u][v];
            }
        b[u]=true;
    }while (!b[n]);
    return L[n];
}
//---------------------------------------------------------
int main(){
    freopen("RB_Path.inp", "r", stdin);
    freopen("RB_Path.out", "w", stdout);
    doc();
    cout<< dijkstra();
    return 0;
}
