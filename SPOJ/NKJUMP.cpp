// SPOJ submission 15807320 (C++ 5) plaintext list. Status: AC, problem NKJUMP, contest SPOJVN. By mansblacks (Khang), 2015-12-08 06:55:38.
#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
#define for(i,first,last) for (int i=first; i<=last; i++)
#define fill(object, value) memset(object, sizeof(object), value)
using namespace std;
 
int n, dem;
long t[10001], L[1001], d[1001];
bool a[1001][1001], b[1001];
//---------------------------------------------------------
void docfile(){
    cin>> n;
    for(i,1,n){
        cin>> t[i];
    }
}
//---------------------------------------------------------
void xuat(int x){
    cout<< x;
}
//---------------------------------------------------------
int tim(int l, int r, long x){
    int m=t[(l+r)/2];
    if(l>r) return(-1);
    else if(x==m) return((l+r)/2);
    else if(x>m) return(tim((l+r)/2+1, r, x));
    else return(tim(l, (l+r)/2-1, x));
}
//---------------------------------------------------------
void build(){
    int k;
    fill(a, 0);
    sort(t+1,t+n+1);
    for(i,1,n-1)
        for(j,i+1,n){
            k=tim(1,n,t[i]+t[j]);
            if(k>0){
                a[i][k]=true;
                a[j][k]=true;
            }
        }
}
//---------------------------------------------------------
void DFS(int u){
    b[u]=true;
    for(v,1,n)
        if((!b[v]) && (a[u][v])) DFS(v);
    L[dem]=u; dem--;
}
//---------------------------------------------------------
void topo(){
    int u, v, dmax;
    fill(d,0); fill(b,0);
    dem=n; dmax=0;
    for(i,1,n)
        if(!b[i]) DFS(i);
    for(i,1,n-1){
        for(j,i+1,n){
            u=L[i]; v=L[j];
            if((a[u][v]) && (d[v]<d[u]+1)){
                d[v]=d[u]+1;
                dmax=fmax(dmax,d[v]);
            }
        }
    }
    xuat(dmax+1);
}
//---------------------------------------------------------
int main(){
    docfile();
    build();
    topo();
    return 0;
} 