#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int N=2009;

int a[N], g[N][N], n;

void doc(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i];
}

void makeEdges(){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            g[i][j] = g[j][i] = a[i]^a[j];
}

void xuly(){
    makeEdges();
    priority_queue<ii> q;
    int b[N]={}, numEdge=0; b[0]=1;
    long long ans=0;
    for(int i=1; i<n; i++) q.push(ii(g[0][i],i));
    while(!q.empty() && numEdge<n-1){
        int u=q.top().second;
        if(b[u]) {q.pop(); continue;}
        ans+=q.top().first; b[u]=1; q.pop(); numEdge++;
        for(int v=0; v<n; v++)
            if(!b[v]) q.push(ii(g[u][v],v));
    }
    cout<< ans;
}

int main(){
    freopen("SuperBall.inp","r",stdin);
    freopen("SuperBall.out","w",stdout);
    doc();
    xuly();
    return 0;
}
