#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=109;

int n, m, a[N][N]={};

int main(){
    // freopen("DaiLy.inp","r",stdin);
    // freopen("DaiLy.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j) a[i][j]=10E8;
    
    for(int i=0; i<m; i++){
        int x,y,val; cin>> x>> y>> val;
        a[x-1][y-1]=a[y-1][x-1]=min(a[x-1][y-1],val);
    }
    
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
    
    int ans=0, minFar=10E8, maxFar;
    for(int i=0; i<n; i++){
        maxFar = 0;
        for(int j=0; j<n; j++)
            if(a[i][j]!=10E8) maxFar = max(maxFar, a[i][j]);
        if(maxFar<minFar){
            ans=i; minFar=maxFar;
        }
    }
    printf("%d\n",ans+1);
    return 0;
}
