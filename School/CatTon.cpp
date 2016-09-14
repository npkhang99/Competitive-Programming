#include <iostream>
#include <stdio.h>
#include <algorithm>
#define fi "CatTon.inp"
#define fo "CatTon.out"
using namespace std;

const int inf=10000000;
int L[35][35][55];
//---------------------------------------------------------
int cat(int n, int m, int k){
    if (L[n][m][k]<inf) return L[n][m][k];
    if (n*m<k) return L[n][m][k]=inf;
    if (k==0 || n*m==k) return L[n][m][k]=0;
    if (n*n==k || m*m==k) return L[n][m][k]=min(n*n, m*m);
    for (int i=1; i<=n-1; i++)
        for (int u=0; u<=k; u++)
            L[n][m][k] = min(L[n][m][k], cat(i, m, u) + cat(n-i, m, k-u) + m*m);
    for (int i=1; i<=m-1; i++)
        for (int u=0; u<=k; u++)
            L[n][m][k] = min(L[n][m][k], cat(n, i, u) + cat(n, m-i, k-u) + n*n);
    return L[n][m][k];
}
//---------------------------------------------------------
int main(){
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    int n, m, k;
    cin>> n>> m>> k;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            for (int f=0; f<=k; f++)
                L[i][j][f] = inf;
    cout<< cat(n, m, k);
    return 0;
}