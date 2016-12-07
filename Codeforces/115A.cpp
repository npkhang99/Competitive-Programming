#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int N=2009;

int n, b[N]={}, c[N]={};
vector<int> a[N];

void doc(){
    cin>> n;
    for(int i=0; i<n; i++){
        int x; cin>> x;
        c[i]=1;
        if(x==-1){ c[i]=-1; continue; }
        a[x-1].push_back(i);
    }
}

void DFS(int u, int k){
    b[u]=1; c[u]=k;
    for(int i=0; i<a[u].size(); i++){
        int v=a[u][i];
        if(!b[v]) DFS(v,k+1);
    }
}

void xuly(){
    for(int i=0; i<n; i++)
        if(!b[i] && c[i]==-1) DFS(i,1);
    int ans=1;
    for(int i=0; i<n; i++){
        // printf("%d ",c[i]);
        ans=max(ans,c[i]);
    }
    // printf("\n");
    printf("%d\n",ans);
}

int main(){
    doc();
    xuly();
    return 0;
}
