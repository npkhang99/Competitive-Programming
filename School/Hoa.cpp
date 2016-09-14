#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N=1009;
int n, m, a[N][N], L[N][N];
//---------------------------------------------------------
void doc(){
    cin>> m>> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>> a[i][j];
}
//---------------------------------------------------------
void ddi(int i, int j){
    if(i>0 && j>0){
        if(L[i][j]==L[i-1][j-1]+a[i][j]){
            ddi(i-1,j-1);
            cout<<i << " "<< j<< endl;
        }else ddi(i,j-1);
    }
}
//---------------------------------------------------------
void xuly(){
    memset(L,0,sizeof(L));
    for(int i=1; i<=n; i++)
        for(int j=i; j<=m-n+i; j++)
            L[i][j]=max(L[i][j-1], L[i-1][j-1]+a[i][j]);
    cout<< L[n][m]<< endl;
    ddi(n,m);
}
//---------------------------------------------------------
int main(){
    freopen("Hoa.inp","r",stdin);
    freopen("Hoa.out","w",stdout);
    doc();
    xuly();
    return 0;
}