// Finding Minimum Spanning Tree Using DSUF (Disjoin Set Union-Find)
// http://vn.spoj.com/problems/QBMST/
#include <stdio.h>         // scanf printf
#include <algorithm>       // sort
using namespace std;

const int N=100009;

struct Edge{
    int u,v,val;
}a[N];

int n, m, parent[N]={};

int findRoot(int p){
    if(parent[p]==p) return p;
    else return parent[p] = findRoot(parent[p]);
}

void join(int p, int q){
    parent[findRoot(p)] = findRoot(q);
}

int comp(Edge a, Edge b){
    return a.val<b.val;
}

int kruskal(){
    int ans = 0;
    for(int i=0; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++)
        if(findRoot(a[i].u) != findRoot(a[i].v)){
            join(a[i].u,a[i].v);
            ans+=a[i].val;
        }
    return ans;
}

int main(){
    scanf("%d%d\n",&n,&m);
    for(int i=0; i<m; i++){
        int x,y,z; scanf("%d%d%d\n",&x,&y,&z);
        a[i].u = x; a[i].v = y; a[i].val = z;
    }
    sort(a,a+m,comp);
    printf("%d\n",kruskal());
    return 0;
}
