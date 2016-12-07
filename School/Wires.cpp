#include <iostream>
#include <stdio.h>
using namespace std;

const int N=1009;

int n, a[N], L[N][N]={};

int main(){
    freopen("Wires.inp","r",stdin);
    freopen("Wires.out","w",stdout);
    cin>> n;
    for(int i=1; i<=n; i++) cin>> a[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[j]==i) L[i][j]=max(L[i][j],L[i-1][j-1]+1);
            else L[i][j]=max(L[i-1][j], L[i][j-1]);
    printf("%d\n",L[n][n]);
    return 0;
}
