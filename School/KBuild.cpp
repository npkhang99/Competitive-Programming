#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory.h>
#define forit(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
using namespace std;

const int N=200009;
vector < vector<int> > g(N),a(N);
int n, d[N], cha[N], dem;
bool b[N];
//---------------------------------------------------------
void doc(){
    cin>> n;
    for(int i=1; i<=n-1; i++){
        int x,y;
        cin>> x>> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
//---------------------------------------------------------
void DFS(int i){
    b[i]=true;
    forit(it,g[i])
        if (!b[*it]){
            a[i].push_back(*it);
            d[*it]=d[i]+1;
            cha[*it]=i;
            DFS(*it);
        }
}
//---------------------------------------------------------
void LCA(int u, int v){
    if(d[u]>=d[v]){
        while(d[u]>d[v]){
            u=cha[u];
            if(!b[u]) dem++;
            b[u]=true;
        }
        while(u!=v){
            if(!b[u]) dem++;
            if(!b[v]) dem++;
            b[u]=true; b[v]=true;
            u=cha[u]; v=cha[v];
        }
    }else LCA(v,u);
}
//---------------------------------------------------------
void xuly(){
    int m, x, y;
    d[1]=1; cha[1]=0; DFS(1);
    //for(int i=1; i<=n; i++) cout<< cha[i]<< " ";
    cin>> m; dem=0; memset(b,false,n+1);
    for(int i=1; i<=m; i++){
        cin>> x>> y;
        LCA(x,y);
    }
}
//---------------------------------------------------------
int main(){
    freopen("KBuild.inp","r",stdin);
    freopen("KBuild.out","w",stdout);
    doc();
    xuly();
    cout<< n-dem-1;
    return 0;
}
