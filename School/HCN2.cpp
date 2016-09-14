#include <iostream>
#include <stdio.h>
using namespace std;

const int N=39;

int n, m, a[N][N], b[N][N]={};

int main(){
    // freopen("HCN2.inp","r",stdin);
    // freopen("HCN2.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>> a[i][j];
    int ans=0;
    for(int i1=0; i1<n; i1++)
        for(int j1=0; j1<m; j1++){
            if(b[i1][j1]) continue;
            int curr = a[i1][j1], lim_n, lim_m;
            ans+=1;
            for(int i=i1; i<n; i++) if(a[i][j1]==curr) lim_n = i+1;
            for(int j=j1; j<m; j++) if(a[i1][j]==curr) lim_m = j+1;
            for(int i=i1; i<lim_n; i++)
                for(int j=j1; j<lim_j; j++)
                    
        }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) printf("%d ",b[i][j]);
        printf("\n");
    }
    cout<< ans<< endl;
    return 0;
}