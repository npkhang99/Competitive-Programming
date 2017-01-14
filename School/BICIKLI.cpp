#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N=10009;

int n, b[N], d[N], d1[N], d2[N], isInf=0;
vector<int> a[N], _a[N];
long long ans=0;

void doc(){
    int m;
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int x,y; cin>> x>> y;
        a[x].push_back(y); _a[y].push_back(x);
    }
}

void DFS1(int u){
    d1[u]=true;
    for(int i=0; i<a[u].size(); i++){
        int v=a[u][i];
        if(!d1[v]) DFS1(v);
    }
}

void DFS2(int u){
    d2[u]=true;
    for(int i=0; i<_a[u].size(); i++){
        int v=_a[u][i];
        if(!d2[v]) DFS2(v);
    }
}

void BFS(){
    queue<int> q;
    q.push(1);
    while(!q.empty() && !isInf){
        int u=q.front(); q.pop();
        if(u==2) {ans++; continue;}
        b[u]=true;
        for(int i=0; i<a[u].size(); i++){
            int v=a[u][i];
            if(!b[v] && d[v]) q.push(v);
            else if(b[v] && d[v]){cout<< "Inf"; return;}
        }
    }
    cout<< ans%10000000000;
}

void xuly(){
    for(int i=1; i<=n; i++) b[i]=d[i]=d1[i]=d2[i]=false;
    DFS1(1); DFS2(2);
    for(int i=1; i<=n; i++)
        if(d1[i] && d2[i]) d[i]=true;
    BFS();
}

int main(){
    freopen("BICIKLI.inp","r",stdin);
    // freopen("BICIKLI.out","w",stdout);
    doc();
    xuly();
    return 0;
}
