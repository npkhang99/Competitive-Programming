#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int N=1009;

int n, m, a[N][N]={}, d=1, T[N];
vector<ii> b;

void uni(int u, int v){
    if(T[u]==T[v]) return;
    d+=1;
    int k = T[v];
    for(int i=0; i<n; i++)
        if(T[i]==k) T[i] = T[u];
}

int main(){
    // freopen("gangs.inp","r",stdin);
    // freopen("gangs.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=0; i<m; i++){
        int x,y;
        char ch;
        cin>> ch>> x>> y;
        if(ch=='F') a[x-1][y-1] = a[y-1][x-1] = 1;
        else a[x-1][y-1] = a[y-1][x-1] = -1;
        if(ch=='F') b.push_back(ii(x-1,y-1));
    }    
    vector<int> E[N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j]==-1) E[i].push_back(j);
    for(int i=0; i<n; i++)
        for(int j=1; j<E[i].size(); j++){
            int u = E[i][j-1], v = E[i][j];
            b.push_back(ii(u,v));
        }
    for(int i=0; i<n; i++) T[i]=i;
    for(int i=0; i<b.size(); i++)
        uni(b[i].first,b[i].second);
    printf("%d\n",n-d+1);
    return 0;
}