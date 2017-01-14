#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define all(seq) seq.begin(),seq.end()
#define fi first
#define se second

typedef pair<int,int> ii;

const int N=100009;

int n, m, k, d[N]={}, c[N]={};
vector<int> a[N], choose;

void BFS(){
    queue<int> q;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    for(int ver:choose) q.push(ver), d[ver] = 0, c[ver] = ver;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i];
            if(c[v] && c[v]!=c[u]){
                printf("%d\n",d[v]+d[u]+1);
                return;
            }
            if(!c[v] && d[v] > d[u]+1) d[v] = d[u]+1, q.push(v), c[v] = c[u];
        }
    }
}

int main(){
    // freopen("ReInvent.inp","r",stdin);
    // freopen("ReInvent.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0; i<k; i++){
        int x; scanf("%d",&x);
        choose.push_back(x);
    }
    BFS();
    return 0;
}
